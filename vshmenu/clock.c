#include <pspsdk.h>

const int cpu_list[] = { 0, 20, 75, 100, 133, 222, 266, 300, 333 }; //0x00002284
const int bus_list[] = { 0, 10, 37, 50, 66, 111, 133, 150, 166 }; //0x000022A8

#define N_CPUS (sizeof(cpu_list) / sizeof(int))
#define N_BUSS (sizeof(bus_list) / sizeof(int))

int limit(int val, int min, int max)
{
	if(val < min) val = max;
	if(val > max) val = min;
	return val;
}

//0x000008E0
int GetCPUSpeed(int cpu)
{
    int i;
	for(i = 0; i < N_CPUS; i++) if(cpu_list[i] == cpu) return i;
	return 0;
}

//0x00000914
int GetBUSSpeed(int bus)
{
    int i;
	for(i = 0; i < N_BUSS; i++) if(bus_list[i] == bus) return i;
	return 0;
}