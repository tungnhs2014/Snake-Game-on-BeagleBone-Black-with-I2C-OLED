BBB_KERNEL := /home/tungnhs/Working_Linux/BBB/bb-kernel/KERNEL/
TOOLCHAIN := /home/tungnhs/Working_Linux/BBB/gcc-8.5.0-nolibc/arm-linux-gnueabi/bin/arm-linux-gnueabi-

EXTRA_CFLAGS=-Wall

# Khai báo cả hai module
obj-m := button_driver.o ssd1306_driver.o

# Khai báo các file phụ thuộc cho ssd1306_driver
ssd1306_driver-objs := ssd1306_driver.o ssd1306_lib.o

BIN_DIR := ../bin
OBJ_DIR := ../obj

# Target build tất cả
all:
	make ARCH=arm CROSS_COMPILE=$(TOOLCHAIN) -C $(BBB_KERNEL) M=$(shell pwd) modules
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)
	@mv *.ko $(BIN_DIR) 2>/dev/null || true
	@mv *.o *.mod.* .*.cmd *.mod modules.order Module.symvers $(OBJ_DIR) 2>/dev/null || true

# Target clean
clean:
	make -C $(BBB_KERNEL) M=$(shell pwd) clean
	rm -rf $(BIN_DIR)/*.ko
	rm -rf $(OBJ_DIR)/*
