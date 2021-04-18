	.set noreorder

#include "pspstub.s"

	STUB_START	"LoadCoreForKernel",0x00010011,0x00060005
	STUB_FUNC	0xBEF0A05E,sceKernelFindModuleByName620
	STUB_FUNC	0x452C5524,sceKernelFindModuleByAddress620
	STUB_FUNC	0x77E8F516,sceKernelFindModuleByUID620
	STUB_FUNC	0xB0466E46,sceKernelCheckExecFile620
	STUB_FUNC	0x8C712A03,sceKernelLinkLibraryEntries620
	STUB_FUNC	0xB95FA50D,sceKernelProbeExecutableObject620
	STUB_END