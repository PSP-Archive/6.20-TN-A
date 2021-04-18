#ifndef __CONF_H__
#define __CONF_H__

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

int sctrlSESetConfigEx(TNConfig *config, int size);
int sctrlSESetConfig(TNConfig *config);

int sctrlSEGetConfigEx(TNConfig *config, int size);
int sctrlSEGetConfig(TNConfig *config);

#endif