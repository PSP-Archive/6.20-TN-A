#include <pspsdk.h>
#include <pspkernel.h>
#include <psploadexec_kernel.h>
#include <pspthreadman_kernel.h>

#include "main.h"

extern int psp_model;

//0x0000618C
int	sctrlHENIsSE()
{
	return 1;
}

//0x00006194
int	sctrlHENIsDevhook()
{
	return 0;
}

//0x0000619C
int sctrlHENGetVersion()
{
	return 0x00001000;
}

//0x000061A4
int sctrlSEGetVersion()
{
    return 0x00020000;
}

//0x000061B0
PspIoDrv *sctrlHENFindDriver(char *drvname)
{
	int k1 = pspSdkSetK1(0);

	SceModule2 *mod = sceKernelFindModuleByName620("sceIOFileManager");
	u32 text_addr = mod->text_addr;

	u32 *(* GetDevice)(char *) = (void *)text_addr + 0x2A38;

	u32 *u = GetDevice(drvname);
	if(!u)
	{
		pspSdkSetK1(k1);
		return 0;
	}

	pspSdkSetK1(k1);

	return (PspIoDrv *)u[1];
}

//0x0000A6A8
int sctrlKernelLoadExecVSHWithApitype(int apitype, const char *file, struct SceKernelLoadExecVSHParam *param)
{
	int k1 = pspSdkSetK1(0);

	SceModule2 *mod = sceKernelFindModuleByName620("sceLoadExec");
	u32 text_addr = mod->text_addr;

	int (* LoadExecVSH)(int apitype, const char *file, struct SceKernelLoadExecVSHParam *param, int unk2);

	if(psp_model == 4) LoadExecVSH = (void *)text_addr + 0x2558;
	else LoadExecVSH = (void *)text_addr + 0x2304;

	int res = LoadExecVSH(apitype, file, param, 0x10000);

	pspSdkSetK1(k1);

	return res;
}

//0x000062AC
int sctrlKernelExitVSH(struct SceKernelLoadExecVSHParam *param)
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelExitVSHVSH620(param);
	pspSdkSetK1(k1);
	return res;
}

//0x000062F8
int sctrlKernelLoadExecVSHMs4(const char *file, struct SceKernelLoadExecVSHParam *param)
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelLoadExecVSHMs4620(file, param);
	pspSdkSetK1(k1);
	return res;
}

//0x00006354
int sctrlKernelLoadExecVSHMs3(const char *file, struct SceKernelLoadExecVSHParam *param)
{
	int k1 = pspSdkSetK1(0);	
	int res = sceKernelLoadExecVSHMs3620(file, param);
	pspSdkSetK1(k1);
	return res;
}

//0x000063B0
int sctrlKernelLoadExecVSHMs2(const char *file, struct SceKernelLoadExecVSHParam *param)
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelLoadExecVSHMs2620(file, param);
	pspSdkSetK1(k1);
	return res;
}

//0x0000640C
int sctrlKernelLoadExecVSHMs1(const char *file, struct SceKernelLoadExecVSHParam *param)
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelLoadExecVSHMs1620(file, param);
	pspSdkSetK1(k1);
	return res;
}

//0x00006468
int sctrlKernelLoadExecVSHDiscUpdater(const char *file, struct SceKernelLoadExecVSHParam *param)
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelLoadExecVSHDiscUpdater620(file, param);
	pspSdkSetK1(k1);
	return res;
}

//0x000064C4
int sctrlKernelLoadExecVSHDisc(const char *file, struct SceKernelLoadExecVSHParam *param)
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelLoadExecVSHDisc620(file, param);
	pspSdkSetK1(k1);
	return res;
}

//0x00006520
int sctrlKernelSetUserLevel(int level)
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelGetUserLevel();

	SceModule2 *mod = sceKernelFindModuleByName620("sceThreadManager");
	u32 text_addr = mod->text_addr;

	u32 *thstruct = (u32 *)_lw(text_addr + 0x19E80);
	thstruct[0x14/4] = (level ^ 8) << 28;

	pspSdkSetK1(k1);
	return res;
}

//0x000066D4
int sctrlKernelSetDevkitVersion(int version)
{
	int k1 = pspSdkSetK1(0);
	int prev = sceKernelDevkitVersion620();

	_sh(version >> 16, 0x88011AAC);
	_sh(version & 0xFFFF, 0x88011AB4);

	ClearCaches();

	pspSdkSetK1(k1);
	return prev;
}