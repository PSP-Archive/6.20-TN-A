#ifndef __SYSMODPATCHES_H__
#define __SYSMODPATCHES_H__

u32 FindPowerFunction(u32 nid);
void SetSpeed(int cpu, int bus);

void OnImposeLoad();
void PatchWlan(u32 text_addr);
void PatchPower(u32 text_addr);
void PatchUmdCache(u32 text_addr);
void PatchMediaSync(u32 text_addr);
void PatchVshMain(u32 text_addr);
void PatchSysconfPlugin(u32 text_addr);
void PatchMsVideoMainPlugin(u32 text_addr);
void PatchGamePlugin(u32 text_addr);
void PatchUpdatePlugin(u32 text_addr);

#endif