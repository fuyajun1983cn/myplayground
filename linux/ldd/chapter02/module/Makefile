obj-m := hello.o
KERNELDIR = /usr/src/linux-headers-$(shell uname -r)
PWD := $(shell pwd)
all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

