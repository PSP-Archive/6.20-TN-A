TARGET = vshmenu
OBJS = main.o clock.o blit.o scePaf.o scePower.o exports.o

CFLAGS = -O2 -Os -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

BUILD_PRX = 1
PRX_EXPORTS = exports.exp

USE_USER_LIBS = 1
USE_USER_LIBC = 1

LIBS = -lpspsystemctrl_user -lpspkubridge -lpspvshctrl

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak