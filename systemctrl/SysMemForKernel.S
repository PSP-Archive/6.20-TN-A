	.set noreorder

#include "pspstub.s"

	STUB_START	"SysMemForKernel",0x00010011,0x000A0005
	STUB_FUNC	0xC6A782DA,sceKernelCreateHeap620
	STUB_FUNC	0x96BFE779,sceKernelAllocHeapMemory620
	STUB_FUNC	0xC2A8C491,sceKernelFreeHeapMemory620
	STUB_FUNC	0xA60B6316,sceKernelHeapTotalFreeSize620
	STUB_FUNC	0xE5E18A99,sceKernelAllocPartitionMemory620
	STUB_FUNC	0xFEB5C72B,sceKernelGetBlockHeadAddr620
	STUB_FUNC	0x31DFE03F,sceKernelSetDdrMemoryProtection620
	STUB_FUNC	0x864EBFD7,sceKernelGetModel620
	STUB_FUNC	0xFE9BC18B,sceKernelDevkitVersion620
	STUB_FUNC	0x957A966D,sceKernelGetSystemStatus620
	STUB_END
