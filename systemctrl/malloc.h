#ifndef __MALLOC_H__
#define __MALLOC_H__

void oe_free(void *p);
void *oe_malloc(size_t size);
int mallocinit();

#endif