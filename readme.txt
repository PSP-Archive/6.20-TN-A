(6.20 TN-A (HEN) by Total_Noob)
-------------------------------
www.total-noob.blogspot.com
www.pspgen.com

(What's this?)
TN HEN allows you to execute homebrews and plugins. It includes a TN VSH Menu for some nifty features. It's similar to the Custom Firmware - without ISO/CSO and PSX support.

(Requirements)
- A PSP with 6.20 installed.

(Instructions)
- Install Patapon Demo & HBL on your PSP.
- Extract EBOOT.PBP to /PSP/GAME/HEN/EBOOT.PBP, or to /HBL/GAME/EBOOT.PBP if you want to launch it directly.
- Launch Patapon Demo and load exploited savedata (Continue).
- Now, it jumps into HEN mode.
- Enjoy homebrews and plugins (you'll lost HEN mode, if you reset/shutdown the device or if your PSP is crashed).

(TN VSH Menu & Features)
The TN VSH Menu can be opened/closed with SELECT in the XMB.

This nice menu allows you to change TN configurations, like:
 - CPU CLOCK XMB
 - CPU CLOCK GAME
 - FAKE REGION (if you changed this option, use RESTART VSH to see new categories/options in the XMB)
 - SKIP GAMEBOOT
 - HIDE MAC ADDRESS (hides the MAC address in System Information)
 - TN NETWORK UPDATE (downloads the newest TN revision)
 - HIDE PIC0 & PIC1 (hides PIC0.PNG and PIC1.PNG in Game)
 - SPOOF VERSION (spoofes System Version in System Information)
 - SLIM COLORS - USB CHARGE (on a PSP phat you can enable slim colors, else on other PSPs you can enable USB chargement)
 - FAST SCROLL MUSIC
 - PROTECT FLASH0 (protects against noobs who write into flash0)

(For developers)
You can get/set the TN config with sctrlSEGetConfig/sctrlSESetConfig.

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

If you find some important unresolved NID's please tell me (sysreg and syscon aren't complete)

(Notes)
- If you own a PSPgo do this great tricky:
  - Pause a game while you're in HEN mode.
  - If you lost HEN mode, you don't need to launch Patapon Demo, just resume game and you're in HEN mode again;)
- If you find a bug, please don't write to me immediately. Collect some bugs and then send me a list and I'll fix these bugs in the next revision.

(Credits)
- Dark_AleX: For his great custom firmware.
- Dr. Soup: For much help while developing.
- GENyUS: For some help.
- Wololo: For betatesting.
- Torch: For the fast scroll music src.
- Bubbletune: For the slim colors src.
- Davee: For some tips.

---------------------------------------------------------------

Merry christmas and happy new year:D