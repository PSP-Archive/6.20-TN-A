#include <pspkernel.h>
#include <string.h>
#include "main.h"

SceUID heapid = -1; //0x0000A75C

//0x00005CC8
void oe_free(void *ptr)
{
    Kprintf("freex: %d\n", sceKernelHeapTotalFreeSize620(heapid));
    sceKernelFreeHeapMemory620(heapid, ptr);
}

//0x00005D14
void *oe_malloc(SceSize size)
{
    Kprintf("free: %d\n", sceKernelHeapTotalFreeSize620(heapid));
	return sceKernelAllocHeapMemory620(heapid, size);
}

//0x00005D60
int mallocinit()
{
	int size = 44 * 1024;

	int keyconfig = sceKernelInitKeyConfig();
    if(keyconfig == PSP_INIT_KEYCONFIG_VSH)
	{
		size = 14 * 1024;
	}
    else if(keyconfig == PSP_INIT_KEYCONFIG_GAME && sceKernelInitApitype() == 0x123)
	{
		return 0;
	}

	heapid = sceKernelCreateHeap620(PSP_MEMORY_PARTITION_KERNEL, size, 1, "");

	return (heapid < 0) ? heapid : 0;
}