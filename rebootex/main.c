#include <psptypes.h>
#include "systemctrl.h"

int Main(void *, void *, void *, void *);

int _start(void *, void *, void *, void *) __attribute__((section(".text.start")));
int _start(void *a0, void *a1, void *a2, void *a3)
{
    return Main(a0, a1, a2, a3);
}

#define MAKE_JUMP(a, f) _sw(0x08000000 | (((u32)(f) & 0x0FFFFFFC) >> 2), a);
#define MAKE_CALL(a, f) _sw(0x0C000000 | (((u32)(f) >> 2) & 0x03FFFFFF), a);

typedef struct BtcnfHeader
{
	u32 signature;
	u32 devkit;
	u32 unknown[2];
	u32 modestart;
	int nmodes;
	u32 unknown2[2];
	u32 modulestart;
	int nmodules;
	u32 unknown3[2];
	u32 modnamestart;
	u32 modnameend;
	u32 unknown4[2];
}  __attribute__((packed)) BtcnfHeader;

typedef struct ModeEntry
{
	u16 maxsearch;
	u16 searchstart;
	int mode1;
	int mode2;
	int reserved[5];
} __attribute__((packed)) ModeEntry;

typedef struct ModuleEntry
{
	u32 stroffset;
	int reserved;
	u16 flags;
	u8 loadmode;
	u8 signcheck;
	int reserved2;
	u8 hash[0x10];
} __attribute__((packed)) ModuleEntry;

u32 reboot_phat[] =
{
	0x82AC, 0x8420, 0x83C4, 0x565C, 0x26DC, 0x274C, 0x2778, 0x70F0,
	0x3798, 0x379C, 0x26D4, 0x2728, 0x2740, 0x5550, 0x5554, 0x5558, 0x7388
};

u32 reboot_other[] =
{
    0x8374, 0x84E8, 0x848C, 0x5724, 0x27A4, 0x2814, 0x2840, 0x71B8,
	0x3860, 0x3864, 0x279C, 0x27F0, 0x2808, 0x5618, 0x561C, 0x5620, 0x7450
};

int (* Real_Reboot)(void *a0, void *a1, void *a2, void *a3) = (void *)0x88600000;
int (* DcacheClear)(void) = (void *)0x88600938;
int (* IcacheClear)(void) = (void *)0x886001E4;

int (* sceBootLfatOpen)(char *file);
int (* sceBootLfatRead)(void *buf, int size);
int (* sceBootLfatClose)(void);
int (* sceKernelCheckPspConfig)(void *buf, int size);

int (* memlmd_CA560AA6)(void *buf, int size, int *retSize);
int (* memlmd_2E208358)(u8 *buf, int size);

char *reboot_module_after;
void *reboot_buf;
int reboot_size;
int reboot_flags;

int hen_found;
int rtm_found;

__attribute__((noinline)) int _memcmp(char *m1, char *m2, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
	    if(m1[i] != m2[i])
		{
		    return m2[i] - m1[i];
		}
	}
	return 0;
}

__attribute__((noinline)) void _memset(u8 *m1, int c, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
	    m1[i] = c;
	}
}

__attribute__((noinline)) void _memcpy(u8 *m1, u8 *m2, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
	    m1[i] = m2[i];
	}
}

__attribute__((noinline)) int _strlen(char *str)
{
    int i = 0;
    while(*str)
    {
	    str++;
        i++;
    }
    return i;
}

void ClearCaches()
{
    DcacheClear();
	IcacheClear();
}

int sceBootLfatReadPatched(void *buf, int size)
{
    if(hen_found)
	{
	    _memcpy(buf, (void *)systemctrl, size_systemctrl);
		return size_systemctrl;
	}
    else if(rtm_found)
	{
	    _memcpy(buf, (void *)reboot_buf, reboot_size);
		return reboot_size;
	}
	return sceBootLfatRead(buf, size);
}

int sceBootLfatOpenPatched(char *file)
{
    if(_memcmp(file, "/hen.prx", 9) == 0)
	{
	    hen_found = 1;
		return 0;
	}
    else if(_memcmp(file, "/rtm.prx", 9) == 0)
	{
	    rtm_found = 1;
		return 0;
	}
	return sceBootLfatOpen(file);
}

int sceBootLfatClosePatched(void)
{
    if(hen_found)
	{
	    hen_found = 0;
		return 0;
	}
    else if(rtm_found)
	{
	    rtm_found = 0;
		return 0;
	}
    return sceBootLfatClose();
}

int AddModule(BtcnfHeader *header, char *module_after, char *new_module, int flags)
{
    ModuleEntry *modules = (ModuleEntry *)((u32)header + header->modulestart);

    char *modnamestart = (char *)((u32)header + header->modnamestart);
    char *modnameend = (char *)((u32)header + header->modnameend);

	/* Add new_module at end */
	int len_new_module = _strlen(new_module) + 1;
    _memcpy((void *)modnameend, (void *)new_module, len_new_module);
	header->modnameend += len_new_module;

	/* Search module_after */
    int i;
    for(i = 0; i < header->nmodules; i++)
    {
        if(_memcmp(modnamestart + modules[i].stroffset, module_after, _strlen(module_after) + 1) == 0)
        {
            break;
        }
    }

	if(i == header->nmodules) return -2;

    /* Set ModuleEntry of new_module */
    ModuleEntry module;
    _memset((void *)&module, 0, sizeof(ModuleEntry));
    module.stroffset = modnameend - modnamestart;
    module.flags = flags;
    module.loadmode = 1;
    module.signcheck = 0x80;

	/* Move module_after 0x20 forward */
    char temp[(header->nmodules - i) * sizeof(ModuleEntry) + modnameend + len_new_module - modnamestart];
    _memcpy((void *)temp, (void *)(modules + i), sizeof(temp));
    _memcpy((void *)(modules + i + 1), (void *)temp, sizeof(temp));

    /* Add ModuleEntry of new_module */
    _memcpy((void *)(modules + i), (void *)&module, sizeof(ModuleEntry));

	/* Fix header */
    header->nmodules++;
    header->modnamestart += sizeof(ModuleEntry);
    header->modnameend += sizeof(ModuleEntry);

	if(header->nmodes <= 0) return -3;

	for(i = 0; i < header->nmodes; i++)
	{
		ModeEntry *modes = (ModeEntry *)((u32)header + header->modestart);
		modes[i].maxsearch++;
	}

	return 0;
}

int sceKernelCheckPspConfigPatched(BtcnfHeader *header, int size)
{
    int res = sceKernelCheckPspConfig(header, size);
	AddModule(header, "/kd/init.prx", "/hen.prx", 0xFF);
	if(reboot_module_after) AddModule(header, reboot_module_after, "/rtm.prx", reboot_flags);
	return res;
}

int memlmd_CA560AA6_patched(void *buf, int size, int *retSize)
{
    if(*(u32 *)(buf + 0x130) == 0xB301AEBA)
    {
	    int gzip_size = *(u32 *)(buf + 0xB0);
        _memcpy(buf, buf + 0x150, gzip_size);
		*retSize = gzip_size;
        return 0;
    }
    return memlmd_CA560AA6(buf, size, retSize);
}

int memlmd_2E208358_patched(u8 *buf, int size)
{
	int i;
	for(i = 0; i < 0x58; i++) if(buf[0xD4 + i]) return memlmd_2E208358(buf, size);
	return 0;
}

int PatchLoadCore(void *a0, void *a1, void *a2, int (* module_bootstart)(void *, void *, void *))
{
	u32 text_addr = ((u32)module_bootstart) - 0xBC4;

    MAKE_CALL(text_addr + 0x41A4, memlmd_CA560AA6_patched);
    MAKE_CALL(text_addr + 0x68F0, memlmd_CA560AA6_patched);

    MAKE_CALL(text_addr + 0x6914, memlmd_2E208358_patched);
    MAKE_CALL(text_addr + 0x6944, memlmd_2E208358_patched);
    MAKE_CALL(text_addr + 0x69DC, memlmd_2E208358_patched);

    memlmd_CA560AA6 = (void *)text_addr + 0x8374;
	memlmd_2E208358 = (void *)text_addr + 0x835C;

	ClearCaches();

	return module_bootstart(a0, a1, a2);
}

int Main(void *a0, void *a1, void *a2, void *a3)
{
    int psp_model = *(u32 *)0x88FB0000;

    u32 *ofs;
	if(psp_model == 0) ofs = reboot_phat;
	else ofs = reboot_other;

    sceBootLfatOpen = (void *)0x88600000 + ofs[0];
    sceBootLfatRead = (void *)0x88600000 + ofs[1];
    sceBootLfatClose = (void *)0x88600000 + ofs[2];
    sceKernelCheckPspConfig = (void *)0x88600000 + ofs[3];

	/* Patch calls */
    MAKE_CALL(0x88600000 + ofs[4], sceBootLfatOpenPatched);
    MAKE_CALL(0x88600000 + ofs[5], sceBootLfatReadPatched);
    MAKE_CALL(0x88600000 + ofs[6], sceBootLfatClosePatched);
    MAKE_CALL(0x88600000 + ofs[7], sceKernelCheckPspConfigPatched);

	/* Patch sceKernelDipsw to return 1 */
    _sw(0x03E00008, 0x88600000 + ofs[8]);
    _sw(0x24020001, 0x88600000 + ofs[9]);

    _sw(0, 0x88600000 + ofs[10]);
    _sw(0, 0x88600000 + ofs[11]);
    _sw(0, 0x88600000 + ofs[12]);

    /* Patch call to LoadCore module_bootstart */
    _sw(0x00113821, 0x88600000 + ofs[13]);
    MAKE_JUMP(0x88600000 + ofs[14], PatchLoadCore);
    _sw(0x02A0E821, 0x88600000 + ofs[15]);

	/* Remove check of return code from the check of the hash in pspbtcnf */
    _sw(0, 0x88600000 + ofs[16]);

	reboot_module_after = (char *)(*(u32 *)0x88FB0010);
	reboot_buf = (void *)(*(u32 *)0x88FB0014);
	reboot_size = *(u32 *)0x88FB0018;
    reboot_flags = *(u32 *)0x88FB001C;

    hen_found = 0;
	rtm_found = 0;

    ClearCaches();

    return Real_Reboot(a0, a1, a2, a3);
}