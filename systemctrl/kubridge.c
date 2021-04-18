#include <pspsdk.h>
#include <pspkernel.h>
#include <string.h>
#include <pspthreadman_kernel.h>

#include "main.h"

//0x00005F48
int kuKernelGetModel()
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelGetModel620();
	pspSdkSetK1(k1);
	return res;
}

 //0x00005F8C
int kuKernelSetDdrMemoryProtection(void *addr, int size, int prot)
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelSetDdrMemoryProtection620(addr, size, prot);
	pspSdkSetK1(k1);
	return res;
}

//0x00005FF8
int kuKernelGetUserLevel(void)
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelGetUserLevel();
	pspSdkSetK1(k1);
	return res;
}

//0x0000603C
int kuKernelInitKeyConfig()
{
	return sceKernelInitKeyConfig();
}

//0x00006044
int kuKernelBootFrom()
{
	return sceKernelBootFrom();
}

//0x0000604C
int kuKernelInitFileName(char *filename)
{
	int k1 = pspSdkSetK1(0);
	strcpy(filename, sceKernelInitFileName());
	pspSdkSetK1(k1);
	return 0;
}

//0x0000609C
int kuKernelInitApitype()
{
	return sceKernelInitApitype();
}

 //0x000060A4
SceUID kuKernelLoadModuleWithApitype2(int apitype, const char *path, int flags, SceKernelLMOption *option)
{
 	int k1 = pspSdkSetK1(0);
	int res = sceKernelLoadModuleWithApitype2620(apitype, path, flags, option);
	pspSdkSetK1(k1);
	return res;
}

//0x00006120
SceUID kuKernelLoadModule(const char *path, int flags, SceKernelLMOption *option)
{
	int k1 = pspSdkSetK1(0);
	int res = sceKernelLoadModule620(path, flags, option);
	pspSdkSetK1(k1);
	return res;
}