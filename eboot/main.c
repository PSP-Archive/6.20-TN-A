#include <pspkernel.h>
#include <pspuser.h>
#include <psputilsforkernel.h>
#include <psputility.h>
#include <string.h>
#include <systemctrl.h>

#include "rebootex.h"

PSP_MODULE_INFO("TN Homebrew Enabler", 0, 1, 0);

#define MAKE_CALL(a, f) _sw(0x0C000000 | (((u32)(f) >> 2) & 0x03FFFFFF), a);

int sceKernelPowerLock(int a0, int a1);

u32 loadexec_go[] = { 0x2F28, 0x2F74 };
u32 loadexec_other[] = { 0x2CD8, 0x2D24 };

int psp_model;

int (* decompress_kle)(void *outbuf, u32 outcapacity, void *inbuf, void *unk);

int decompress_kle_patched(void *outbuf, u32 outcapacity, void *inbuf, void *unk)
{
    int (* KernelGzipDecompress)(u8 *dest, u32 destSize, const u8 *src, u32 unknown) = (void *)0x8800FA10;
	int size = KernelGzipDecompress((void *)0x88FC0000, 0x10000, rebootex, 0);

    int i;
	for(i = 0; i < 0x20; i++) ((char *)0x88FB0000)[i] = 0;

	*(u32 *)0x88FB0000 = psp_model;
	*(u32 *)0x88FB0004 = size;

    return decompress_kle(outbuf, outcapacity, inbuf, unk);
}

#define LOADCORE_ADDR 0x88017100

int PatchLoadExec()
{
	SceModule2 *(*sceKernelFindModuleByName620)(const char *name) = (void *)LOADCORE_ADDR + 0x7A78;

	SceModule2 *mod = (SceModule2 *)sceKernelFindModuleByName620("sceLoadExec");
	u32 text_addr = mod->text_addr;

    int (* KernelGetModel)() = (void *)0x8800A1C4;
	psp_model = KernelGetModel();

	u32 *ofs;
	if(psp_model == 4) ofs = loadexec_go;
	else ofs = loadexec_other;

	decompress_kle = (void *)text_addr;
	MAKE_CALL(text_addr + ofs[0], decompress_kle_patched);
	_sw(0x3C0188FC, text_addr + ofs[1]);

    /* Fix destroyed offsets */
	*(u32 *)0x8800CCB0 = 0xACC24230;
	*(u32 *)0x8800CCB4 = 0x0A003322;
	*(u32 *)0x8800CCB8 = 0x00001021;
	*(u32 *)0x8800CCBC = 0x3C058801;

    int (* _sceKernelIcacheInvalidateAll)() = (void *)0x88000E98;
    int (* _sceKernelDcacheWritebackInvalidateAll)() = (void *)0x88000744;

	_sceKernelIcacheInvalidateAll();
	_sceKernelDcacheWritebackInvalidateAll();

	return 0;
}

void ClearCaches()
{
	sceKernelIcacheInvalidateAll();
	sceKernelDcacheWritebackInvalidateAll();
}

void ErrorCrash(char *msg)
{
	pspDebugScreenPrintf("Error: %s.", msg);
	asm("break\n");
}

int main()
{
    pspDebugScreenInit();

	/* Check compatible firmware */
	if(sceKernelDevkitVersion() != 0x06020010) ErrorCrash("Incompatible firmware");

	/* Load required module */
    pspUtilityHtmlViewerParam params;
	memset(&params, 0, sizeof(pspUtilityHtmlViewerParam));
	params.base.size = sizeof(pspUtilityHtmlViewerParam);
	params.base.accessThread = 19;
	if(sceUtilityHtmlViewerInitStart(&params) < 0) ErrorCrash("Could not load module");

	sceKernelDelayThread(1 * 1000 * 1000);

	/* Search module addr */
	u32 text_addr = 0x08800000;

	while(1)
	{
	    if(_lw(text_addr) == 0x56656373 && _lw(text_addr + 4) == 0x56486873) break;
		else if(text_addr >= 0x0A000000) ErrorCrash("Could not find module address");
		text_addr += 4;
	}

	text_addr -= 0xBC00;

	int (* sceUtility_private_2DC8380C)(int slot) = (void *)text_addr + 0xB978;
	int (* sceUtility_private_764F5A3C)(int slot, SceUID cbid) = (void *)text_addr + 0xB990;

	/* Search -1 */
	memset((void *)0x08800000, 0, 0x100000);
	sceUtility_private_2DC8380C(0x08080000);
	ClearCaches();

	u32 mem = 0x08800000;

	while(1)
	{
	    if(_lw(mem) == -1) break;
		else if(mem >= 0x08900000) ErrorCrash("Could not initialize exploit");
		mem += 4;
	}

	/* Patch sceKernelPowerLock */
    sceUtility_private_764F5A3C((0x0880CCB0 - mem) >> 4, sceKernelCreateCallback("", NULL, NULL));
	ClearCaches();

	/* Jump to kernel proc */
    *(u32 *)0x08804234 = 0x08800000;
	*(u32 *)0x08800010 = (int)PatchLoadExec;
	ClearCaches();

	sceKernelPowerLock(0, 0x08800000);

	sceKernelExitGame();

	return 0;
}