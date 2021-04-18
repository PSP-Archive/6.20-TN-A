	.set noreorder

#include "pspstub.s"

	STUB_START "scePaf",0x00090000,0x00020005
	STUB_FUNC  0xE8473E80,scePafSprintf
	STUB_FUNC  0x23C8DAB5,scePafMemcpy
	STUB_END
