PSPDEV		= /pspsdk/bin
INCLUDES	= -I $(PSPDEV)/../psp/sdk/include

all:	rebootex.bin

rebootex.bin:
	$(PSPDEV)/psp-gcc $(INCLUDES) -W -Wall -O2 -G0 -fno-pic -S main.c -o main.s
	$(PSPDEV)/psp-as main.s -o main.o
	$(PSPDEV)/psp-ld -T linkfile.l main.o -o main.elf
	$(PSPDEV)/psp-strip -s main.elf
	$(PSPDEV)/psp-objcopy -O binary main.elf rebootex.bin

clean:
	rm -rf *~ *.o *.elf *.bin *.S