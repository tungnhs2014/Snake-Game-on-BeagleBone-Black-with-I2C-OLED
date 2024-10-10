BBB_KERNEL:= /home/tungnhs/Working_Linux/BBB/bb-kernel/KERNEL/
TOOLCHAIN:= /home/tungnhs/Working_Linux/BBB/gcc-8.5.0-nolibc/arm-linux-gnueabi/bin/arm-linux-gnueabi-

EXTRA_CFLAGS=-Wall
obj-m := ssd1306_oled_driver.o
ssd1306_oled_driver-objs = ssd1306_lib.o ssd1306_driver.o

all:
	make ARCH=arm CROSS_COMPILE=$(TOOLCHAIN) -C $(BBB_KERNEL) M=$(shell pwd) modules
	
clean:
	make -C $(BBB_KERNEL) M=$(shell pwd) clean
