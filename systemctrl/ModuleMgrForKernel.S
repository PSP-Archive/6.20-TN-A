	.set noreorder

#include "pspstub.s"

	STUB_START	"ModuleMgrForKernel",0x00090011,0x00070005
	STUB_FUNC	0xB691CB9F,sceKernelLoadModuleWithApitype2620
	STUB_FUNC	0xE3CCC6EA,sceKernelLoadModule620
	STUB_FUNC	0x329C89DB,sceKernelLoadModuleVSH620
	STUB_FUNC	0x5352C26C,sceKernelLoadModuleBuffer620
	STUB_FUNC	0xDF8FFFAB,sceKernelStartModule620
	STUB_FUNC	0xAAFA90C2,sceKernelStopModule620
	STUB_FUNC	0x9CEB18C4,sceKernelUnloadModule620
	STUB_END
