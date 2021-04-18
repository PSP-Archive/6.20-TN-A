#include <pspsdk.h>
#include <pspkernel.h>
#include <psputilsforkernel.h>
#include <systemctrl.h>
#include <stdio.h>
#include <string.h>

#include "nid_table.h"

#include "main.h"
#include "sysmodpatches.h"
#include "malloc.h"
#include "plugins.h"
#include "conf.h"

PSP_MODULE_INFO("SystemControl", 0x3007, 2, 5);

/* ELF file header */
typedef struct
{
	u32	e_magic;
	u8 e_class;
	u8 e_data;
	u8 e_idver;
	u8 e_pad[9];
	u16 e_type; 
	u16 e_machine; 
	u32 e_version; 
	u32	e_entry; 
	u32	e_phoff; 
	u32	e_shoff; 
	u32	e_flags; 
	u16	e_ehsize; 
	u16	e_phentsize; 
	u16	e_phnum;
	u16	e_shentsize; 
	u16	e_shnum; 
	u16	e_shstrndx; 
} __attribute__((packed)) Elf32_Ehdr;

/* ELF section header */
typedef struct
{
	u32	sh_name; 
	u32	sh_type; 
	u32	sh_flags; 
	u32	sh_addr;
	u32	sh_offset; 
	u32	sh_size; 
	u32	sh_link;
	u32	sh_info;
	u32	sh_addralign;
	u32	sh_entsize;
} __attribute__((packed)) Elf32_Shdr;

u32 mesgled_phat[] = { 0x1E3C, 0x3808, 0x3BC4, 0x1ECC };
u32 mesgled_slim[] = { 0x1ECC, 0x3D10, 0x415C, 0x1F5C };
u32 mesgled_brite[] = { 0x1F5C, 0x41F0, 0x4684, 0x1FEC };
u32 mesgled_go[] = { 0x1FEC, 0x4674, 0x4B50, 0x207C };

u32 memlmd_phat[] = { 0xF10, 0x1158, 0x10D8, 0x112C, 0xE10, 0xE74 };
u32 memlmd_other[] = { 0xFA8, 0x11F0, 0x1170, 0x11C4, 0xEA8, 0xF0C };

extern u32 set_p2;
extern u32 set_p8;

extern TNConfig config;

char *rebootex;
int size_rebootex;
int psp_model;

u32 apitype_addr;
u32 filename_addr;
u32 keyconfig_addr;

int (* new_decPBP)(u32 *tag, u8 *keys, u32 code, u32 *buf, int size, int *retSize, int m, void *unk0, int unk1, int unk2, int unk3, int unk4); //0x0000A780
int (* new_decPRX)(u32 *buf, int size, int *retSize, int m); //0x0000A784

int set_cpuspeed = 0;

STMOD_HANDLER module_handler; //0x0000A78C
SceUID modmgrstart_thid; //0x0000A794
SceModule2 *modmgrstart_module; //0x0000A798

int (* ProbeExec1)(void *buf, u32 *check); //0x0000A79C
int (* PartitionCheck)(u32 *addr, u32 *check); //0x0000A7A0
int (* ProbeExec2)(u8 *buf, u32 *check); //0x0000A7A4

int (* scramble)(u32 *buf, int size, int m);
int (* decPRX)(u32 *buf, int size, int *retSize, int m);

int (* memlmd_keyseed)(int unk, u32 addr);

int (* decPBP)(u32 *tag, u8 *keys, u32 code, u32 *buf, int size, int *retSize, int m, void *unk0, int unk1, int unk2, int unk3, int unk4); //0x0000A7B4

u32 buf[256/4]; //0x0000AA84
/*
#define log(...) { char msg[256]; sprintf(msg,__VA_ARGS__); logmsg(msg); }

void logmsg(char *msg)
{
    SceUID fd = sceIoOpen("ms0:/log.txt", PSP_O_WRONLY | PSP_O_CREAT, 0777);
    if(fd > 0)
    {
        sceIoLseek(fd, 0, PSP_SEEK_END);
        sceIoWrite(fd, msg, strlen(msg));
        sceIoClose(fd);
    }
}
*/
//0x0000005C
int IsStaticElf(void *buf)
{
	Elf32_Ehdr *header = (Elf32_Ehdr *)buf;
	if(header->e_magic == 0x464C457F && header->e_type == 2) return 1;
	return 0;
}

//0x00000094
int PatchExec2(void *buf, int *check)
{
	int index = check[0x4C/4];
	if(index < 0) index += 3;

	u32 addr = (u32)(buf + index);
	if(addr >= 0x88400000 && addr <= 0x88800000) return 0;

	check[0x58/4] = ((u32 *)buf)[index/4] & 0xFFFF;
	return ((u32 *)buf)[index/4];
}

//0x000000E8
int PatchExec1(void *buf, int *check)
{
	if(((u32 *)buf)[0] != 0x464C457F) return -1;

    if(check[8/4] >= 0x120)
	{
		if(check[8/4] != 0x120 && check[8/4] != 0x141 && check[8/4] != 0x142 && check[8/4] != 0x143 && check[8/4] != 0x140) return -1;

		if(check[0x10/4] == 0)
		{
			if(check[0x44/4] != 0)
			{
				check[0x48/4] = 1;
				return 0;
			}
			return -1;
		}

		check[0x48/4] = 1;
		check[0x44/4] = 1;
		PatchExec2(buf, check);

		return 0;
	}
	else if(check[8/4] >= 0x52) return -1;

    if(check[0x44/4] != 0) 
	{ 
		check[0x48/4] = 1; 
		return 0;
	} 

	return -2;
}

//0x000001B0
int ProbeExec1Patched(void *buf, u32 *check)
{
	int res = ProbeExec1(buf, check);

	if(((u32 *)buf)[0] != 0x464C457F) return res;

	u16 *modinfo = ((u16 *)buf) + (check[0x4C/4] / 2);

	u16 realattr = *modinfo;
	u16 attr = realattr & 0x1E00;

	if(attr != 0)
	{
		u16 attr2 = ((u16 *)check)[0x58/2];
		attr2 &= 0x1E00;

		if(attr2 != attr) ((u16 *)check)[0x58/2] = realattr;
	}

	if(check[0x48/4] == 0) check[0x48/4] = 1;

	return res;
}

int sceKernelProbeExecutableObjectPatched(void *buf, int *check)
{
    int res = sceKernelProbeExecutableObject620(buf, check);

	if(((u32 *)buf)[0] == 0x464C457F)
	{
	    if(check[8/4] >= 0x52)
	    {
	        if(check[0x20/4] == -1);
	        {
		        if(IsStaticElf(buf))
		        {
			        check[0x20/4] = 3;
			        return 0;
				}
			}
		}
	}

	return res;
}

//0x00000248
__attribute__((noinline)) char *GetStrTab(u8 *buf)
{
	Elf32_Ehdr *header = (Elf32_Ehdr *)buf;
	if(header->e_magic != 0x464C457F) return NULL;

	u8 *pData = buf + header->e_shoff;

	int i;
	for(i = 0; i < header->e_shnum; i++)
	{
		if(header->e_shstrndx == i)
		{
			Elf32_Shdr *section = (Elf32_Shdr *)pData;
			if(section->sh_type == 3) return (char *)buf + section->sh_offset;
		}
		pData += header->e_shentsize;
	}

	return NULL;
}

//0x000011F4
int ProbeExec2Patched(u8 *buf, u32 *check)
{
	int res = ProbeExec2(buf, check);

	if(((u32 *)buf)[0] != 0x464C457F) return res;

	if(IsStaticElf(buf)) if((check[8/4] - 0x140) < 0x5) check[8/4] = 0x120; //Fake apitype to avoid reject

	if(check[0x4C/4] == 0)
	{
		if(IsStaticElf(buf))
		{
			char *strtab = GetStrTab(buf);
			if(strtab)
			{
				Elf32_Ehdr *header = (Elf32_Ehdr *)buf;
				u8 *pData = buf + header->e_shoff;

				int i;
				for(i = 0; i < header->e_shnum; i++)
				{
					Elf32_Shdr *section = (Elf32_Shdr *)pData;

					if(strcmp(strtab + section->sh_name, ".rodata.sceModuleInfo") == 0)
					{
						check[0x4C/4] = section->sh_offset;
						check[0x58/4] = 0;
					}

					pData += header->e_shentsize;
				}
			}
		}
	}

	return res;
}

//0x0000137C
int PartitionCheckPatched(u32 *st0, u32 *check)
{
	SceUID fd = (SceUID)st0[0x18/4];
	u16 attributes;

	u32 pos = sceIoLseek(fd, 0, PSP_SEEK_CUR);
	if(pos < 0) return PartitionCheck(st0, check);

	/* rewind to beginning */
	sceIoLseek(fd, 0, PSP_SEEK_SET);
	if(sceIoRead(fd, buf, 256) < 256)
	{
		sceIoLseek(fd, pos, PSP_SEEK_SET);
		return PartitionCheck(st0, check);
	}

	/* go to module info offset */
	if(buf[0] == 0x50425000) /* PBP */
	{
		sceIoLseek(fd, buf[0x20/4], PSP_SEEK_SET);
		sceIoRead(fd, buf, 0x14);

		if(buf[0] != 0x464C457F) /* ELF */
		{
			/* Encrypted module */
			sceIoLseek(fd, pos, PSP_SEEK_SET);
			return PartitionCheck(st0, check);
		}

		sceIoLseek(fd, buf[0x20/4] + check[0x4C/4], PSP_SEEK_SET);

		if(!IsStaticElf(buf)) check[0x10/4] = buf[0x24/4] - buf[0x20/4]; // Allow psar's in decrypted pbp's
	}
	else if(buf[0] == 0x464C457F) /* ELF */
	{
		sceIoLseek(fd, check[0x4C/4], PSP_SEEK_SET);
	}
	else /* encrypted module */
	{
		sceIoLseek(fd, pos, PSP_SEEK_SET);
		return PartitionCheck(st0, check);
	}

	sceIoRead(fd, &attributes, 2);

	if(IsStaticElf(buf)) check[0x44/4] = 0;
	else
	{
		if(attributes & 0x1000) check[0x44/4] = 1;
		else check[0x44/4] = 0;
	}

	sceIoLseek(fd, pos, PSP_SEEK_SET);
	return PartitionCheck(st0, check);
}

//0x000015A4
int PatchExec3(void *buf, int *check, int isPlain, int res)
{
	if(!isPlain) return res;

	if(check[8/4] >= 0x52)
	{
		if(check[0x20/4] == -1); if(IsStaticElf(buf)) check[0x20/4] = 3;
		return res;
	}

	if(!(PatchExec2(buf, check) & 0x0000FF00)) return res;

	check[0x44/4] = 1;	
	return 0;
}

//0x00001644
int sceKernelCheckExecFilePatched(u32 *buf, int *check)
{
	int res = PatchExec1(buf, check);
	if(res == 0) return res;

	int isPlain = (((u32 *)buf)[0] == 0x464C457F); //ELF

	res = sceKernelCheckExecFile620(buf, check);

	return PatchExec3(buf, check, isPlain, res);
}

//0x000002E4
__attribute__((noinline)) u32 ResolveNid(NidTable *nid_table, u32 nid)
{
    int i;
	for(i = 0; i < nid_table->n_nid; i++) if(nid_table->nid[i].old_nid == nid) return nid_table->nid[i].new_nid;
	return 0;
}

//0x00000324
void SystemCtrlForKernel_6A5F76B5(int a0)
{
    //unk_A790 = a0;
}

//0x00000330
STMOD_HANDLER sctrlHENSetStartModuleHandler(STMOD_HANDLER handler)
{
	STMOD_HANDLER prev = module_handler;
	module_handler = (STMOD_HANDLER)((u32)handler | 0x80000000);
	return prev;
}

//0x00000348
int scramble_patched(u32 *buf, int size, int m)
{
	if(((u32 *)buf)[0] == 0x5053507E)
	{
		int i;
		for(i = 0; i < 0x58; i++)
		{
	        if(((u8 *)buf)[0xD4 + i] && ((u32 *)buf)[0xB8/4] && ((u32 *)buf)[0xBC/4])
			{
	            return scramble(buf, size, m);
			}
		}
	}
	return 0;
}

//0x000003B4
void *SetNewDecPRX(int (* handler)(u32 *buf, int size, int *retSize, int m))
{
    void *res = new_decPRX;
    new_decPRX = handler;
    return res;
}

//0x000003C4
void *SetNewDecPBP(int (* handler)(u32 *tag, u8 *keys, u32 code, u32 *buf, int size, int *retSize, int m, void *unk0, int unk1, int unk2, int unk3, int unk4))
{
    void *res = new_decPBP;
    new_decPBP = handler;
    return res;
}

//0x000003D4
__attribute__((noinline)) void sctrlHENPatchSyscall(u32 addr, void *newaddr)
{
    void **ptr;
    asm("cfc0 %0, $12\n" : "=r" (ptr));

	int i;
    for(i = 0; i < 0x10000; i++)
    {
		if(((u32 *)(*ptr + 0x10))[i] == addr) ((u32 *)(*ptr + 0x10))[i] = (u32)newaddr;
    }
}

//0x00000404
int decPBPPatched(u32 *tag, u8 *keys, u32 code, u32 *buf, int size, int *retSize, int m, void *unk0, int unk1, int unk2, int unk3, int unk4)
{
	if(new_decPBP) if(new_decPBP(tag, keys, code, buf, size, retSize, m, unk0, unk1, unk2, unk3, unk4) >= 0) return 0;

	if(tag && buf && retSize)
	{
		if(buf[0x130/4] == 0x28796DAA || buf[0x130/4] == 0x7316308C || buf[0x130/4] == 0x3EAD0AEE || buf[0x130/4] == 0x8555ABF2)
		{
			if(((u8 *)buf)[0x150] == 0x1F && ((u8 *)buf)[0x151] == 0x8B)
			{
				int gzip_size = buf[0xB0/4];
				*retSize = gzip_size;
				memmove(buf, buf + 0x150/4, gzip_size);
				return 0;
			}
		}
	}

	int res = decPBP(tag, keys, code, buf, size, retSize, m, unk0, unk1, unk2, unk3, unk4);
	if(res < 0) if(scramble_patched(buf, size, m) >= 0) return decPBP(tag, keys, code, buf, size, retSize, m, unk0, unk1, unk2, unk3, unk4);

	return res;
}

//0x00000600
int decPRXPatched(u32 *buf, int size, int *retSize, int m)
{
    if(new_decPRX) if(new_decPRX(buf, size, retSize, m) >= 0) return 0;

	if(buf && retSize)
	{
		if(buf[0x130/4] == 0xC6BA41D3 || buf[0x130/4] == 0x55668D96)
		{
			if(((u8 *)buf)[0x150] == 0x1F && ((u8 *)buf)[0x151] == 0x8B)
			{
				int gzip_size = buf[0xB0/4];
				*retSize = gzip_size;
				memmove(buf, buf + 0x150/4, gzip_size);
				return 0;
			}
		}
	}

    int res = decPRX(buf, size, retSize, m);
	if(res < 0)
	{
		if(scramble_patched(buf, size, m) >= 0)
		{
			memlmd_keyseed(0, 0xBFC00200);
			return decPRX(buf, size, retSize, m);
		}
	}

	return res;
}

//0x00000760
NidTable *CheckKernelLib(const char *libname)
{
    if(libname)
	{
		int i = 0;
	    do
	    {
		    if(strcmp(libname, nid_table_620[i].libname) == 0) return nid_table_620 + i;
			i++;
	    }
		while(i < NIDS_N);
	}
    return 0;
}

//0x000007E4
int sceKernelStartThreadPatched(SceUID thid, SceSize arglen, void *argp)
{
    if(thid == modmgrstart_thid)
	{
	    modmgrstart_thid = -1;
		if(modmgrstart_module && module_handler) module_handler(modmgrstart_module);
	}
    return sceKernelStartThread(thid, arglen, argp);
}

//0x00000860
SceUID sceKernelCreateThreadPatched(const char *name, SceKernelThreadEntry entry, int initPriority, int stackSize, SceUInt attr, SceKernelThreadOptParam *option)
{
    SceUID res = sceKernelCreateThread(name, entry, initPriority, stackSize, attr, option);
	if(res >= 0)
	{
        if(strcmp(name, "SceModmgrStart") == 0)
        {
            modmgrstart_thid = res;
            modmgrstart_module = sceKernelFindModuleByAddress620((SceUID)entry);
        }
	}
	return res;
}

//0x000008D4
u32 sctrlHENFindFunction(const char *szMod, const char *szLib, u32 nid)
{
	struct SceLibraryEntryTable *entry;
	SceModule2 *pMod;

	pMod = sceKernelFindModuleByName620(szMod);
	if(!pMod)
	{
        pMod = sceKernelFindModuleByAddress620((SceUID)szMod);
		if(!pMod) return 0;
	}

    NidTable *nid_table = CheckKernelLib(szLib);
    if(nid_table)
    {
        u32 new_nid = ResolveNid(nid_table, nid);
        if(new_nid) nid = new_nid;
    }

	void *entTab = pMod->ent_top;
	int entLen = pMod->ent_size;

	int i = 0;

	while(i < entLen)
    {
		entry = (struct SceLibraryEntryTable *)(entTab + i);

		int total = entry->stubcount + entry->vstubcount;
	    u32 *vars = entry->entrytable;

        if(entry->libname && strcmp(entry->libname, szLib) == 0)
		{
			if(entry->stubcount > 0)
			{
			    int count;
				for(count = 0; count < entry->stubcount; count++) if(vars[count] == nid) return vars[count + total];
			}
		}
		else
		{
            if(entry->vstubcount > 0)
            {
			    int count;
                for(count = 0; count < entry->vstubcount; count++)
				{
				    if(vars[count + entry->stubcount] == nid) return vars[count + entry->stubcount + total];
				}
			}
		}

		i += (entry->len * 4);
	}

	return 0;
}

//0x000009F8
void ClearCaches()
{
    sceKernelIcacheInvalidateAll();
    sceKernelDcacheWritebackInvalidateAll();
}

int sceKernelLinkLibraryEntriesPatched(void *stub_top, int stub_size)
{
    u32 module_sdk_version = FindProc(stub_top, NULL, 0x11B97506);
	if(module_sdk_version && FIRMWARE_TO_FW(_lw(module_sdk_version)) == 0x620) return sceKernelLinkLibraryEntries620(stub_top, stub_size);

	struct SceLibraryStubTable *sysclib_entry = 0;
	struct SceLibraryStubTable *syscon_entry = 0;
	struct SceLibraryStubTable *power_entry = 0;
	struct SceLibraryEntryTable *entry;
	int i = 0;

	while(i < stub_size)
    {
		entry = (struct SceLibraryEntryTable *)(stub_top + i);

		NidTable *nid_table = CheckKernelLib(entry->libname);

		if(strcmp(entry->libname, "SysclibForKernel") == 0) sysclib_entry = (SceLibraryStubTable *)entry;
        else if(strcmp(entry->libname, "sceSyscon_driver") == 0) syscon_entry = (SceLibraryStubTable *)entry;
        else if(strcmp(entry->libname, "scePower_driver") == 0) power_entry = (SceLibraryStubTable *)entry;

		if(nid_table)
		{
			int count;
			for(count = 0; count < entry->stubcount; count++)
			{
			    u32 *vars = entry->entrytable;
				u32 new_nid = ResolveNid(nid_table, vars[count]);
				if(new_nid) vars[count] = new_nid;
			}
		}

        i += (entry->len * 4);
	}

	ClearCaches();

    int res = sceKernelLinkLibraryEntries620(stub_top, stub_size);

    if(sysclib_entry)
    {
		int count;
		for(count = 0; count < sysclib_entry->stubcount; count++)
		{
		    u32 nid = sysclib_entry->nidtable[count];
			u32 import_addr = (u32)(sysclib_entry->stubtable + (count * 8));

			if(nid == 0x909C228B)
			{
				REDIRECT_FUNCTION(import_addr, 0x88002E80);
				ClearCaches();
			}
			else if(nid == 0x18FE80DB)
			{
				REDIRECT_FUNCTION(import_addr, 0x88002EBC);
				ClearCaches();
			}
		}
	}

    if(syscon_entry)
    {
		int count;
		for(count = 0; count < syscon_entry->stubcount; count++)
		{
		    u32 nid = syscon_entry->nidtable[count];
			u32 import_addr = (u32)(syscon_entry->stubtable + (count * 8));

			if(nid == 0xC8439C57)
			{
			    SceModule2 *mod = sceKernelFindModuleByName620("sceSYSCON_Driver");
				REDIRECT_FUNCTION(import_addr, mod->text_addr + 0x2C64);
				ClearCaches();
			}
		}
	}

    if(power_entry)
    {
		int count;
		for(count = 0; count < power_entry->stubcount; count++)
		{
		    u32 nid = power_entry->nidtable[count];
			u32 import_addr = (u32)(power_entry->stubtable + (count * 8));

			if(nid == 0x737486F2)
			{
			    u32 scePowerSetClockFrequency_k = FindPowerFunction(nid);
				if(scePowerSetClockFrequency_k)
				{
				    REDIRECT_FUNCTION(import_addr, scePowerSetClockFrequency_k);
				    ClearCaches();
				}
			}
		}
	}
/*
	struct SceLibraryStubTable *test;
	int j = 0;

	while(j < stub_size)
    {
		test = (struct SceLibraryStubTable *)(stub_top + j);

		int count;
		for(count = 0; count < test->stubcount; count++)
		{
		    if(_lw(test->stubtable + (count * 8)) == 0x0000054C)
			{
		        log("Missing: Module: %s, Library: %s, NID: 0x%08X\r\n", mod->modname, test->libname, test->nidtable[count]);
			}
		}

        j += (test->len * 4);
	}
*/
    return res;
}

//0x00000C28
void PatchMesgLed() 
{
	SceModule2 *mod = sceKernelFindModuleByName620("sceMesgLed");
	u32 text_addr = mod->text_addr;

	u32 *ofs;
	if(psp_model == 0) ofs = mesgled_phat;
	else if(psp_model == 1) ofs = mesgled_slim;
	else if(psp_model == 2) ofs = mesgled_brite;
	else if(psp_model == 4) ofs = mesgled_go;

	decPBP = (void *)text_addr + 0xE0;

	MAKE_CALL(text_addr + 0x1908, decPBPPatched);
	MAKE_CALL(text_addr + ofs[0], decPBPPatched);
	MAKE_CALL(text_addr + ofs[1], decPBPPatched);
	MAKE_CALL(text_addr + ofs[2], decPBPPatched);
	MAKE_CALL(text_addr + ofs[3], decPBPPatched);
}

//0x00000C8C
void PatchMemlmd()
{
	SceModule2 *mod = sceKernelFindModuleByName620("sceMemlmd");
	u32 text_addr = mod->text_addr;

	u32 *ofs;
	if(psp_model == 0) ofs = memlmd_phat;
	else ofs = memlmd_other;

	scramble = (void *)text_addr + ofs[0];
    decPRX = (void *)text_addr + 0x134;
    memlmd_keyseed = (void *)text_addr + ofs[1];

    MAKE_CALL(text_addr + ofs[2], scramble_patched);
    MAKE_CALL(text_addr + ofs[3], scramble_patched);
    MAKE_CALL(text_addr + ofs[4], decPRXPatched);
    MAKE_CALL(text_addr + ofs[5], decPRXPatched);
}

int sceIoAssignPatched(const char *dev1, const char *dev2, const char *dev3, int mode, void* unk1, long unk2)
{
    int k1 = pspSdkSetK1(0);

	if(mode == IOASSIGN_RDWR && strcmp(dev3, "flashfat0:") == 0)
	{
	    if(!config.notprotectflash0)
		{
		    pspSdkSetK1(k1);
			return -1;
		}
	}

	pspSdkSetK1(k1);
	return sceIoAssign(dev1, dev2, dev3, mode, unk1, unk2);
}

int sceIoMkdirPatched(const char *dir, SceMode mode)
{
	int k1 = pspSdkSetK1(0);

	if(strcmp(dir, "ms0:/PSP/GAME") == 0) sceIoMkdir("ms0:/seplugins", mode);
	else if(strcmp(dir, "ef0:/PSP/GAME") == 0) sceIoMkdir("ef0:/seplugins", mode);

	pspSdkSetK1(k1);
	return sceIoMkdir(dir, mode);
}

void PatchIoFileMgr()
{
	SceModule2 *mod = sceKernelFindModuleByName620("sceIOFileManager");
	u32 text_addr = mod->text_addr;

    sctrlHENPatchSyscall(text_addr + 0x1AAC, sceIoAssignPatched);
    if(sceKernelInitKeyConfig() == PSP_INIT_KEYCONFIG_VSH) sctrlHENPatchSyscall(text_addr + 0x4260, sceIoMkdirPatched);
}

//0x00000D18
void PatchInterruptMgr()
{
	SceModule2 *mod = sceKernelFindModuleByName620("sceInterruptManager");
	u32 text_addr = mod->text_addr;

	/* Allow execution of syscalls in kmode */
	_sw(0, text_addr + 0xE94);
	_sw(0, text_addr + 0xE98);

	/* Remove 0xBC000000 protection */
	_sw(0, text_addr + 0xDE8);
	_sw(0, text_addr + 0xDEC);
}

//0x00000D48
void PatchModuleMgr()
{
	SceModule2 *mod = sceKernelFindModuleByName620("sceModuleManager");
	u32 text_addr = mod->text_addr;

    if(psp_model == 4) MAKE_CALL(text_addr + 0x7C3C, sceKernelProbeExecutableObjectPatched);

	MAKE_JUMP(text_addr + 0x8854, sceKernelCheckExecFilePatched);

    PartitionCheck = (void *)text_addr + 0x7FC0;

	apitype_addr = text_addr + 0x9990;
	filename_addr = text_addr + 0x9994;
	keyconfig_addr = text_addr + 0x99EC;

	_sw(0, text_addr + 0x760);
	_sw(0x24020000, text_addr + 0x7C0);
	_sw(0, text_addr + 0x30B0);
	_sw(0, text_addr + 0x310C);
	_sw(0x10000009, text_addr + 0x3138);
	_sw(0, text_addr + 0x3444);
	_sw(0, text_addr + 0x349C);
	_sw(0x10000010, text_addr + 0x34C8);

	MAKE_CALL(text_addr + 0x64FC, PartitionCheckPatched);
	MAKE_CALL(text_addr + 0x6878, PartitionCheckPatched);

	/* Patch call to translate NIDs */
	MAKE_CALL(text_addr + 0x842C, sceKernelLinkLibraryEntriesPatched);

	/* sceKernelQueryModuleInfo Patch */
	_sw(0, text_addr + 0x4360);
	_sw(0, text_addr + 0x43A8);
	_sw(0, text_addr + 0x43C0);

	MAKE_JUMP(text_addr + 0x894C, sceKernelCreateThreadPatched);
	MAKE_JUMP(text_addr + 0x8994, sceKernelStartThreadPatched);
}

//0x00000E48
void PatchLoadCore()
{
	SceModule2 *mod = sceKernelFindModuleByName620("sceLoaderCore");
	u32 text_addr = mod->text_addr;

	/* Patch calls and references to sceKernelCheckExecFile */
	_sw((u32)sceKernelCheckExecFilePatched, text_addr + 0x86B4);
	MAKE_CALL(text_addr + 0x1578, sceKernelCheckExecFilePatched);
	MAKE_CALL(text_addr + 0x15C8, sceKernelCheckExecFilePatched);
	MAKE_CALL(text_addr + 0x4A18, sceKernelCheckExecFilePatched);

	/* Patch relocation check in switch statement */
    _sw(_lw(text_addr + 0x8B58), text_addr + 0x8B74);

	/* Patch 2 functions called by sceKernelProbeExecutableObject */
	MAKE_CALL(text_addr + 0x46A4, ProbeExec1Patched);
	MAKE_CALL(text_addr + 0x4878, ProbeExec2Patched);

	/* Allow kernel modules to have syscall exports */
	_sw(0x3C090000, text_addr + 0x40A4);

	_sw(0, text_addr + 0x7E84);

	_sw(0, text_addr + 0x6880);
	_sw(0, text_addr + 0x6884);
	_sw(0, text_addr + 0x6990);
	_sw(0, text_addr + 0x6994);

	/* Patch call to init module_bootstart */
	MAKE_CALL(text_addr + 0x1DB0, PatchInit);
	_sw(0x02E02021, text_addr + 0x1DB4); //move $a0, $s7

    ProbeExec1 = (void *)text_addr + 0x61D4;
	ProbeExec2 = (void *)text_addr + 0x60F0;

	/* Restore original calls */
    u32 memlmd_2E208358 = FindProc("sceMemlmd", "memlmd", 0x2E208358);
	MAKE_CALL(text_addr + 0x6914, memlmd_2E208358);
	MAKE_CALL(text_addr + 0x6944, memlmd_2E208358);
	MAKE_CALL(text_addr + 0x69DC, memlmd_2E208358);

    u32 memlmd_CA560AA6 = FindProc("sceMemlmd", "memlmd", 0xCA560AA6);
	MAKE_CALL(text_addr + 0x41A4, memlmd_CA560AA6);
	MAKE_CALL(text_addr + 0x68F0, memlmd_CA560AA6);
}

void MakeDummyVlfFunction(u32 nid)
{
    u32 vlf_proc = FindProc("VLF_Module", "VlfGui", nid);
    if(vlf_proc)
	{
	    MAKE_DUMMY_FUNCTION0(vlf_proc);
	}
}

//0x00000FF4
void OnModuleStart(SceModule2 *mod)
{
    char *modname = mod->modname;
	u32 text_addr = mod->text_addr;

	if(strcmp(modname, "sceLowIO_Driver") == 0)
	{
	    if(mallocinit() < 0)
	    {
		    while(1) _sw(0, 0);
	    }
	}
	else if(strcmp(modname, "sceUmdCache_driver") == 0)
	{
        PatchUmdCache(text_addr);
	}
    else if(strcmp(modname, "sceMediaSync") == 0)
	{
        PatchMediaSync(text_addr);
	}
    else if(strcmp(modname, "sceImpose_Driver") == 0)
	{
        OnImposeLoad();
	}
    else if(strcmp(modname, "sceWlan_Driver") == 0)
	{
		PatchWlan(text_addr);
	}
	else if(strcmp(modname, "scePower_Service") == 0)
	{
		PatchPower(text_addr);
	}
    else if(strcmp(modname, "vsh_module") == 0)
	{
        PatchVshMain(text_addr);
	}
    else if(strcmp(modname, "sysconf_plugin_module") == 0)
	{
        PatchSysconfPlugin(text_addr);
	}
    else if(strcmp(modname, "msvideo_main_plugin_module") == 0)
	{
		PatchMsVideoMainPlugin(text_addr);
    }
    else if(strcmp(modname, "game_plugin_module") == 0)
	{
        PatchGamePlugin(text_addr);
	}
    else if(!config.notusetnnetupd && strcmp(modname, "update_plugin_module") == 0)
	{
        PatchUpdatePlugin(text_addr);
	}
	else if(strcmp(modname, "VLF_Module") == 0)
	{
	    MakeDummyVlfFunction(0x2A245FE6);
	    MakeDummyVlfFunction(0x7B08EAAB);
	    MakeDummyVlfFunction(0x22050FC0);
	    MakeDummyVlfFunction(0x158BE61A);
	    MakeDummyVlfFunction(0xD495179F);
		ClearCaches();
	}

	if(set_cpuspeed == 0)
	{
	    if(sceKernelGetSystemStatus620() == 0x20000)
	    {
		    if(sceKernelInitKeyConfig() == PSP_INIT_KEYCONFIG_GAME)
			{
	            SetSpeed(config.gamecpuspeed, config.gamebusspeed);
			}
			set_cpuspeed = 1;
		}
	}
}

//0x000016C8
int module_bootstart()
{
	psp_model = *(u32 *)0x88FB0000;

    PatchLoadCore();
    PatchModuleMgr();
	PatchMemlmd();
	PatchIoFileMgr();
	PatchInterruptMgr();

	ClearCaches();

	module_handler = (STMOD_HANDLER)((u32)OnModuleStart | 0x80000000);

	size_rebootex = *(u32 *)0x88FB0004;
	set_p2 = *(u32 *)0x88FB0008;
	set_p8 = *(u32 *)0x88FB000C;

	SceUID block_id = sceKernelAllocPartitionMemory620(1, "", PSP_SMEM_High, size_rebootex, NULL);
	if(block_id >= 0)
	{
	    rebootex = sceKernelGetBlockHeadAddr620(block_id);
	    memset(rebootex, 0, size_rebootex);
		memcpy(rebootex, (void *)0x88FC0000, size_rebootex);
	}

	ClearCaches();

    return 0;
}