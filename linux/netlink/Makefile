MODULE_NAME :=net_link
obj-m :=$(MODULE_NAME).o
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD)
	gcc -o sender sender.c
clean:
	rm -fr *.ko *.o *.cmd sender $(MODULE_NAME).mod.c  .built-in.o.cmd
