CC      = arm-none-eabi-gcc
LD      = arm-none-eabi-ld -v
AR      = arm-none-eabi-ar
AS      = arm-none-eabi-as
CP      = arm-none-eabi-objcopy
OD      = arm-none-eabi-objdump
  
CFLAGS  =  -I./ -c -fno-common -O0 -g -mcpu=cortex-m3 -mthumb  
AFLAGS  = -ahls -mcpu=cortex-m3 -mthumb 
LFLAGS  = -Tstm32.ld -nostartfiles
CPFLAGS = -Obinary
ODFLAGS = -S

all: test

clean:
	-rm main.lst main.o main.elf main.lst main.bin startup_stm32f10x.lst startup_stm32f10x.o

test: main.elf
	@ echo "...copying"
	$(CP) $(CPFLAGS) main.elf main.bin
	$(OD) $(ODFLAGS) main.elf > main.lst

main.elf: main.o startup_stm32f10x.o stm32.ld  
	@ echo "..linking"
	$(LD) $(LFLAGS) -o main.elf main.o startup_stm32f10x.o

main.o: main.c
	@ echo ".compiling"
	$(CC) $(CFLAGS) main.c

startup_stm32f10x.o: startup_stm32f10x.s
	@ echo ".assembling"
	$(AS) $(AFLAGS) -o startup_stm32f10x.o startup_stm32f10x.s > startup_stm32f10x.lst
