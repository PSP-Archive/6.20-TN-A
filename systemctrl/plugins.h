#ifndef __PLUGINS_H__
#define __PLUGINS_H__

int PatchInit(int (* module_bootstart)(SceSize, void *), void *argp);

#endif