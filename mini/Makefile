CROSS_COMPILE := arm-none-eabi-
 
all:
	$(CROSS_COMPILE)gcc -I. -c -fno-common -O0 -g -mcpu=cortex-m3 -mthumb main.c
	#$(CROSS_COMPILE)ld -Tstm32.ld -Wl,-Map=main.map -nostartfiles -o main.elf main.o
	$(CROSS_COMPILE)gcc -Tstm32.ld -Wl,-Map=main.map -nostartfiles -o main.elf main.o
	$(CROSS_COMPILE)objcopy -Obinary main.elf main.bin
	$(CROSS_COMPILE)size main.elf
 
clean:
	rm -Rf main.elf main.o main.bin main.map