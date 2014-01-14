ifneq ($(KERNELRELEASE),)
	mymodule-objs:=thread.c
	obj-m += thread.o
else
	PWD :=$(shell pwd)
	KVER := $(shell uname -r)
	KDIR :=/lib/modules/$(KVER)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	rm -fr *.o *.mod.c *.ko *symvers *order *.markers *_
endif


