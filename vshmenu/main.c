#include <pspsdk.h>
#include <pspctrl.h>
#include <pspdisplay.h>
#include <psppower.h>
#include <systemctrl.h>
#include <stdio.h>
#include <string.h>

#include "blit.h"
#include "clock.h"

PSP_MODULE_INFO("TNVshMenu", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(0);

typedef struct
{
	int magic; /* 0x47434E54 */
	int	vshcpuspeed; 
	int	vshbusspeed; 
	int	gamecpuspeed; 
	int	gamebusspeed; 
	int fakeregion;
	int skipgameboot;
	int nothidemacaddress;
	int notusetnnetupd;
	int hidepic0pic1;
	int notspoofversion;
	int usbcharge_slimcolors;
	int fastscrollmusic;
	int notprotectflash0;
	int reversed[2];
} TNConfig;

//0x00002264
char *menu_list[] =
{
    "CPU CLOCK XMB    ",
	"CPU CLOCK GAME   ",
	"FAKE REGION      ",
	"SKIP GAMEBOOT    ",
	"HIDE MAC ADDRESS ",
	"TN NETWORK UPDATE",
	"HIDE PIC0 & PIC1 ",
	"SPOOF VERSION    ",
	"USB CHARGE       ",
	"FAST SCROLL MUSIC",
	"PROTECT FLASH0   ",
	"SHUTDOWN DEVICE",
	"SUSPEND DEVICE",
	"RESET DEVICE",
	"RESTART VSH",
	"EXIT"
};

#define N_MENULIST (sizeof(menu_list) / sizeof(char *))

char *regions[] = { "Disabled", "Japan", "America", "Europe", "Korea", "United Kingdom", "Mexico", "Australia/New Zealand", "East", "Taiwan", "Russia", "China", "Debug Type I", "Debug Type II" };

#define N_REGIONS (sizeof(regions) / sizeof(char *))

char *disenabled[] = { "Disabled", "Enabled" };

extern int cpu_list[]; //0x00002284
extern int bus_list[]; //0x000022A8

int exit_mode; //0x00002474
int menu_mode; //0x00002478
int mode; //0x0000247C

static u32 cur_buttons; //0x00002480
static u32 buttons_on; //0x00002484

SceUID vshmenu_thid; //0x00002488

SceCtrlData pad; //0x0000248C

TNConfig config; //0x0000249C

int changed = 0; //0x0000259C
int menu_sel = 0; //0x000025A0

char *item_str[N_MENULIST]; //0x000025A4
int item_fcolor[N_MENULIST]; //0x000025C4

TNConfig *new_config; //0x000025E4

//0x00000D88
int menu_ctrl(u32 buttons, u32 button_on)
{
    int direction = 0;

    button_on &= 0x0081F3F9;

	if(button_on & PSP_CTRL_DOWN) direction++;
	if(button_on & PSP_CTRL_UP) direction--;

	do
	{
		menu_sel = limit(menu_sel + direction, 0, N_MENULIST - 1);
	} while(menu_list[menu_sel] == NULL);

	direction = -2;
	if(button_on & PSP_CTRL_LEFT) direction = -1;
	if(button_on & PSP_CTRL_CROSS) direction = 0;
	if(button_on & PSP_CTRL_RIGHT) direction = 1;

	if(button_on & PSP_CTRL_SELECT || button_on & PSP_CTRL_HOME)
	{
		direction = 0;
	    menu_sel = 15;
	}

	if(direction > -2)
	{
	    if(changed == 0 && direction != 0) changed = 1;

        if(menu_sel < N_MENULIST)
		{
		    switch(menu_sel)
		    {
		        case 0:
        	        if(direction)
				    {
				        int cpu_num = limit(GetCPUSpeed(new_config->vshcpuspeed) + direction, 0, 8);
				        new_config->vshcpuspeed = cpu_list[cpu_num];
					    new_config->vshbusspeed = bus_list[cpu_num];
				    }
				    break;

		        case 1:
        	        if(direction)
				    {
				        int cpu_num = limit(GetCPUSpeed(new_config->gamecpuspeed) + direction, 0, 8);
				        new_config->gamecpuspeed = cpu_list[cpu_num];
					    new_config->gamebusspeed = bus_list[cpu_num];
				    }
				    break;

		        case 2:
        	        if(direction) new_config->fakeregion = limit(new_config->fakeregion + direction, 0, N_REGIONS - 1);
				    break;

		        case 3:
					if(direction) new_config->skipgameboot = limit(new_config->skipgameboot + direction, 0, 1);
				    break;

		        case 4:
					if(direction) new_config->nothidemacaddress = limit(new_config->nothidemacaddress + direction, 0, 1);
				    break;

		        case 5:
					if(direction) new_config->notusetnnetupd = limit(new_config->notusetnnetupd + direction, 0, 1);
				    break;

		        case 6:
					if(direction) new_config->hidepic0pic1 = limit(new_config->hidepic0pic1 + direction, 0, 1);
				    break;

		        case 7:
					if(direction) new_config->notspoofversion = limit(new_config->notspoofversion + direction, 0, 1);
				    break;

		        case 8:
					if(direction) new_config->usbcharge_slimcolors = limit(new_config->usbcharge_slimcolors + direction, 0, 1);
				    break;

		        case 9:
					if(direction) new_config->fastscrollmusic = limit(new_config->fastscrollmusic + direction, 0, 1);
				    break;

		        case 10:
					if(direction) new_config->notprotectflash0 = limit(new_config->notprotectflash0 + direction, 0, 1);
				    break;

	   		    case 11:
	    		    return -1;

    		    case 12:
		   		    return -2;

	   		    case 13:
	    		    return -3;

    		    case 14:
		   		    return -4;

    		    case 15:
	   			    return direction == 0 ? direction : 1;
	    	}
	    }
	}

	return 1;
}

//0x00000AE8
int menu_setup(TNConfig *conf)
{
    new_config = conf;

    int i;
	for(i = 0; i < N_MENULIST;i++) item_str[i] = NULL;

    static char clock_buf_xmb[8]; //0x000025F0
    static char clock_buf_game[8]; //0x000025F8

	if(GetCPUSpeed(new_config->vshcpuspeed) == 0 || GetBUSSpeed(new_config->vshbusspeed) == 0) scePafSprintf(clock_buf_xmb, "Default");
	else scePafSprintf(clock_buf_xmb, "%d/%d", new_config->vshcpuspeed, new_config->vshbusspeed);
	item_str[0] = clock_buf_xmb;

	if(GetCPUSpeed(new_config->gamecpuspeed) == 0 || GetBUSSpeed(new_config->gamebusspeed) == 0) scePafSprintf(clock_buf_game, "Default");
	else scePafSprintf(clock_buf_game, "%d/%d", new_config->gamecpuspeed, new_config->gamebusspeed);
	item_str[1] = clock_buf_game;

	item_str[2] = regions[new_config->fakeregion];

	item_str[3] = disenabled[new_config->skipgameboot];
	item_str[4] = disenabled[!new_config->nothidemacaddress];
	item_str[5] = disenabled[!new_config->notusetnnetupd];
	item_str[6] = disenabled[new_config->hidepic0pic1];
	item_str[7] = disenabled[!new_config->notspoofversion];
	item_str[8] = disenabled[new_config->usbcharge_slimcolors];
	item_str[9] = disenabled[new_config->fastscrollmusic];
	item_str[10] = disenabled[!new_config->notprotectflash0];
}

//0x00000948
int menu_draw()
{
    if(blit_setup() < 0) return -1;

    blit_set_color(0x00FFFFFF, 0x8000FF00);
    blit_string(24 * 8, 6 * 8, "TN VSH MENU");

	int i;
	for(i = 0; i < N_MENULIST; i++)
	{
		u32 bc = i == menu_sel ? 0x00FF8080 : 0xC00000FF;

		blit_set_color(0x00FFFFFF, bc);

		if(menu_list[i])
		{
		    int x, y = (8 + i) * 8;

		    if(i == 15) x = 27 * 8;
		    else if(i == 14) x = 24 * 8;
		    else if(i == 13) x = 23 * 8;
		    else if(i == 12) x = 22 * 8;
		    else if(i == 11) x = 22 * 8;
		    else x = 17 * 8;

		    blit_string(x, y, menu_list[i]);

			if(item_str[i])
			{
                blit_set_color(0x00FFFFFF, bc);
                blit_string(35 * 8, y, item_str[i]);
			}
		}
	}

	blit_set_color(0x00FFFFFF, 0x00000000);
	
	return 0;
}

//0x00000430
void ctrl_handler(SceCtrlData *pad_data, int count)
{
    scePafMemcpy(&pad, pad_data, sizeof(SceCtrlData));

    buttons_on = ~cur_buttons & pad.Buttons;
    cur_buttons = pad.Buttons;

	int i;
	for(i = 0; i < count; i++) pad_data[i].Buttons &= ~0x0081F3F9;
}

static void buttons_func()
{
    switch(mode)
	{
		case 0:
		    if(cur_buttons && (cur_buttons & PSP_CTRL_SELECT) == 0) mode = 1;
			break;

		case 1:
	        if(menu_mode == 0) menu_mode = 1;
		    else
		    {
		        int res = menu_ctrl(cur_buttons, buttons_on);
			    if(res == 0) mode = 2;
			    else if(res == -1) mode = 3;
			    else if(res == -2) mode = 4;
			    else if(res == -3) mode = 5;
			    else if(res == -4) mode = 6;
		    }
		    break;

		case 2:
	        if((cur_buttons & 0x0083F3F9) == 0) exit_mode = 1;
		    break;

		default:
		    if(mode >= 3 && mode <= 6)
			{
	            if((cur_buttons & 0x0083F3F9) == 0) exit_mode = mode - 1;
			}
	}
}

static void menu_exit()
{
	if(changed) sctrlSESetConfig(&config);

	switch(exit_mode)
	{
	    case 2:
			scePowerRequestStandby();
			break;

	    case 3:
			scePowerRequestSuspend();
			break;

		case 4:
		    scePowerRequestColdReset(0);
			break;

		case 5:
		    sctrlKernelExitVSH(0);
			break;
	}
}

//0x0000010C
int VshMenu_Thread()
{
    sceKernelChangeThreadPriority(0, 8);
	sctrlSEGetConfig(&config);
	vctrlVSHRegisterVshMenu(ctrl_handler);

    while(1)
    {
	    sceDisplayWaitVblankStart();

		if(exit_mode) break;

		switch(menu_mode)
		{
		    case 1:
			    menu_setup(&config);
				menu_mode++;
			    break;
		    case 2:
			    menu_draw();
			    menu_setup(&config);
			    break;
	    }

        buttons_func();
    }

    menu_exit();

	vctrlVSHExitVSHMenu(&config);

    return sceKernelExitDeleteThread(0);
}

//0x00000058
int module_start()
{
    if(kuKernelGetModel() == 0) strcpy(menu_list[8], "SLIM COLORS      ");
	vshmenu_thid = sceKernelCreateThread("VshMenu_Thread", VshMenu_Thread, 0x10, 0x1000, 0, NULL);
	if(vshmenu_thid >= 0) sceKernelStartThread(vshmenu_thid, 0, NULL);
	return 0;
}

//0x00000000
int module_stop()
{
    exit_mode = 1;
	SceUInt timeout = 100000;
	if(sceKernelWaitThreadEnd(vshmenu_thid, &timeout) < 0) sceKernelTerminateDeleteThread(vshmenu_thid);
	return 0;
}