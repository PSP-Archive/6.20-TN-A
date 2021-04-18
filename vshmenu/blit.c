#include <pspkernel.h>
#include <pspdisplay.h>
#include <string.h>

#include "blit.h"

extern u8 msx[];

static int pwidth, pheight, bufferwidth, pixelformat;
static u32* vram32;

static u32 fcolor = 0x00FFFFFF;
static u32 bcolor = 0xFF000000;

__attribute__((noinline)) u32 adjust_alpha(u32 col)
{
	u32 alpha = col >> 24;
	u32 c1, c2;

	if(alpha == 0) return col;
	if(alpha == 0xFF) return col;

	c1 = col & 0x00FF00FF;
	c2 = col & 0x0000FF00;
	u8 mul = (u8)(255 - alpha);
	c1 = ((c1 * mul) >> 8) & 0x00FF00FF;
	c2 = ((c2 * mul) >> 8) & 0x0000FF00;
	return (alpha << 24) | c1 | c2;
}

int blit_setup(void)
{
	int unk;
	sceDisplayGetMode(&unk, &pwidth, &pheight);
	sceDisplayGetFrameBuf((void *)&vram32, &bufferwidth, &pixelformat, &unk);
	if(bufferwidth == 0 || pixelformat != 3) return -1;

	fcolor = 0x00FFFFFF;
	bcolor = 0xFF000000;

	return 0;
}

void blit_set_color(int fg_col, int bg_col)
{
	fcolor = fg_col;
	bcolor = bg_col;
}

int blit_string(int sx, int sy, const char *msg)
{
	int x, y, p;
	u32 c1, c2;

	u32 fg_col = adjust_alpha(fcolor);
	u32 bg_col = adjust_alpha(bcolor);

	if(bufferwidth == 0 || pixelformat != 3) return -1;

	for(x = 0; msg[x] && x < (pwidth / 8); x++)
	{
		char code = msg[x] & 0x7F; // 7bit ANK
		for(y = 0; y < 8; y++)
		{
			int offset = (sy + y) * bufferwidth + sx + x * 8;
			u8 font = y >= 7 ? 0x00 : msx[code * 8 + y];
			for(p = 0; p < 8; p++)
			{
				u32 col = (font & 0x80) ? fg_col : bg_col;
				u32 alpha = col >> 24;
				if(alpha == 0) vram32[offset] = col;
				else if(alpha != 0xFF)
				{
					c2 = vram32[offset];
					c1 = c2 & 0x00FF00FF;
					c2 = c2 & 0x0000FF00;
					c1 = ((c1 * alpha) >> 8) & 0x00FF00FF;
					c2 = ((c2 * alpha) >> 8) & 0x0000FF00;
					vram32[offset] = (col & 0xFFFFFF) + c1 + c2;
				}
				font <<= 1;
				offset++;
			}
		}
	}
	return x;
}