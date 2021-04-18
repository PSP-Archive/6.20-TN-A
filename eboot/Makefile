TARGET = hen
OBJS = main.o

CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

BUILD_PRX = 1

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = TN Homebrew Enabler

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak