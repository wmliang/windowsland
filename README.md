Here is the source and writeup for the challenge "windowsland" in HITCON CTF 2018

the idea is exploiting safe-unlink with dangling pointer in windows user-mode heap

if anyone want to go through the technique directly, please see `unlink_chunk.cpp`

# Vulnerability
---
### bug1: leak
All of the string input did not terminate with NULL-byte during copy, such as `human->name`, `teacher->subject`, `engineer->language`, `doctor->hospital`, `athlete->sport`
### bug2: dangling pointer
When we edit engineer and input empty language, it will `free(engineer->language)`.

However, it did not clean and left the dangling pointer.This lead to double-free and UAF (re-editable)

# Exploitation
---
the following exploit assumption is under LFH-disabled.

the challengable part is bug2. there are two restriction for `engineer->language` buffer

- `language = malloc(0x200+RANDOM&0xF0)`
- `memcpy(language, input, 0x18)`

These make the UAF becomes so hard to overlap/overwrite other structures percisely and reliably

obviously, you still can overwrite the flink/blink(ie. small chunk fd/bk on ptmalloc) of the freed `engineer->language`

is it possible to do the similar old trick under modern windows user-mode heap ?

`unlink_chunk.cpp` demostrates one of the possibility

### leak
In order to achieve the reliable exploit, some heap grooming is neceaary at the beginning

There are two candidates, `vector` for each type of human and `engineer->language`

`vector` is chosen due to its deterministic size

finally, `human->name` is used to leak the old blink, which points to `vector<engineer>` 

### unlink
We compute the address of the danling pointer from the leaked `vecotr<engineer>` address

Then, we can trigger the unlink.

`engineer->language = &engineer->language`

Now, we got arbitrary read/write

The remaining step is familiar, leak stack, ROP, read flag, ...

# Note
---
All detail is explained in `payload.py`

The success rate for the exploit is around 50%, some unreliable is from `engineer->language` random size

The registry, `MaxLoaderThreads`, is used to disable the windows 10 parallel loading feature, which makes the heap non-deterministic

There should be more than one solution, if yes please share :)

