#include <pspsdk.h>
#include <pspkernel.h>
#include <string.h>

#include "conf.h"

//0x00005DDC
int sctrlSESetConfigEx(TNConfig *config, int size)
{
    int k1 = pspSdkSetK1(0);

	SceUID fd = sceIoOpen("flashfat1:/config.tn", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
	if(fd < 0)
	{
	    pspSdkSetK1(k1);
		return -1;
	}

	config->magic = 0x47434E54;

	if(sceIoWrite(fd, config, size) < size)
	{
		sceIoClose(fd);
		pspSdkSetK1(k1);
		return -1;
	}

	sceIoClose(fd);
	pspSdkSetK1(k1);

	return 0;
}

//0x00005E94
int sctrlSESetConfig(TNConfig *config)
{
    return sctrlSESetConfigEx(config, sizeof(TNConfig));
}

//0x00005E9C
int sctrlSEGetConfigEx(TNConfig *config, int size)
{
	int k1 = pspSdkSetK1(0);
    int ret = -1;

	memset(config, 0, size);

	SceUID fd = sceIoOpen("flashfat1:/config.tn", PSP_O_RDONLY, 0);
	if(fd >= 0)
	{
        ret = sceIoRead(fd, config, size);
	    sceIoClose(fd);
	}

	pspSdkSetK1(k1);
	return ret;
}

//0x00005F40
int sctrlSEGetConfig(TNConfig *config)
{
    return sctrlSEGetConfigEx(config, sizeof(TNConfig));
}