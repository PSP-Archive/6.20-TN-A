#ifndef ___MAIN_H___
#define ___MAIN_H___

#include <psploadexec_kernel.h>
#include <pspctrl.h>

#define FW_TO_FIRMWARE(f) ((((f >> 8) & 0xF) << 24) | (((f >> 4) & 0xF) << 16) | ((f & 0xF) << 8) | 0x10)
#define FIRMWARE_TO_FW(f) ((((f >> 24) & 0xF) << 8) | (((f >> 16) & 0xF) << 4) | ((f >> 8) & 0xF))

#define MAKE_JUMP(a, f) _sw(0x08000000 | (((u32)(f) & 0x0FFFFFFC) >> 2), a);
#define MAKE_CALL(a, f) _sw(0x0C000000 | (((u32)(f) >> 2) & 0x03FFFFFF), a);
#define REDIRECT_FUNCTION(a, f) _sw(0x08000000 | (((u32)(f) >> 2) & 0x03FFFFFF), a); _sw(0, a + 4);
#define MAKE_DUMMY_FUNCTION0(a) _sw(0x03E00008, a); _sw(0x00001021, a + 4);
#define MAKE_DUMMY_FUNCTION1(a) _sw(0x03E00008, a); _sw(0x24020001, a + 4);

SceModule2 *sceKernelFindModuleByName620(const char *modname);
SceModule2 *sceKernelFindModuleByAddress620(u32 addr);
SceModule2 *sceKernelFindModuleByUID620(SceUID modid);
int sceKernelCheckExecFile620(u32 *buf, int *check);
int sceKernelLinkLibraryEntries620(void *entTab, int entLen);
int sceKernelProbeExecutableObject620(void *buf, int *check);

SceUID sceKernelLoadModule620(const char *path, int flags, SceKernelLMOption *option);
SceUID sceKernelLoadModuleWithApitype2620(int apitype, const char *path, int flags, SceKernelLMOption *option);
SceUID sceKernelLoadModuleVSH620(const char *path, int flags, SceKernelLMOption *option);
SceUID sceKernelLoadModuleBuffer620(SceSize bufsize, void *buf, int flags, SceKernelLMOption *option);
int sceKernelStartModule620(SceUID modid, SceSize argsize, void *argp, int *status, SceKernelSMOption *option);
int sceKernelStopModule620(SceUID modid, SceSize argsize, void *argp, int *status, SceKernelSMOption *option);
int sceKernelUnloadModule620(SceUID modid);

int sceKernelExitVSHVSH620(struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHMs1620(const char *file, struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHMs2620(const char *file, struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHMs3620(const char *file, struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHMs4620(const char *file, struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHDisc620(const char *file, struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHDiscUpdater620(const char *file, struct SceKernelLoadExecVSHParam *param);

SceUID sceKernelCreateHeap620(SceUID partitionid, SceSize size, int unk, const char *name);
void *sceKernelAllocHeapMemory620(SceUID heapid, SceSize size);
int sceKernelFreeHeapMemory620(SceUID heapid, void *block);
SceSize sceKernelHeapTotalFreeSize620(SceUID heapid);
SceUID sceKernelAllocPartitionMemory620(SceUID partitionid, const char *name, int type, SceSize size, void *addr);
void *sceKernelGetBlockHeadAddr620(SceUID blockid);
int sceKernelSetDdrMemoryProtection620(void *addr, int size, int prot);
int sceKernelDevkitVersion620();
int sceKernelGetModel620();
int sceKernelGetSystemStatus620();

void ClearCaches();
void PatchMesgLed();

#endif