TARGET = systemctrl
OBJS = main.o sysmodpatches.o malloc.o conf.o kubridge.o systemctrl.o plugins.o LoadCoreForKernel.o ModuleMgrForKernel.o SysMemForKernel.o LoadExecForKernel.o exports.o

CFLAGS = -O2 -Os -G0 -Wall -fshort-wchar -fno-pic -mno-check-zero-division
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

BUILD_PRX = 1
PRX_EXPORTS = exports.exp

USE_KERNEL_LIBC = 1
USE_KERNEL_LIBS = 1

LDFLAGS = -Tlinkfile.prx

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak