#ifndef __BLIT_H__
#define __BLIT_H__

int blit_setup(void);
void blit_set_color(int fg_col,int bg_col);
int blit_string(int sx,int sy,const char *msg);

#endif