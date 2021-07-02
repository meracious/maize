CC = gcc
CFLAGS = -Wextra -Wall -O2 -pipe
INTERNALCFLAGS :=	\
			-I src/include/	\
			-ffreestanding	\
			-mno-red-zone	\
			-fno-pic -fpie	\
			-mgeneral-regs-only	\
			-fno-exceptions

LDINTERNALFLAGS :=	\
			-Tscripts/linker.ld	\
			-nostdlib	\
			-shared		\
			-pie -fno-pic -fpie	\
			-z max-page-size=0x1000

CFILES = $(shell find src/ -type f -name '*.c')
ASMFILES = $(shell find src/ -type f -name '*.asm')
OFILES = $(CFILES:.c=.o) $(ASMFILES:.asm=.o)

TARGET = maize.elf
IMAGE = image.hdd

.PHONY: clean all

$(IMAGE): $(TARGET)
	@echo PARTED:: $(IMAGE)
	@dd if=/dev/zero bs=1M count=0 seek=64 of=$(IMAGE)
	@parted -s $(IMAGE) mklabel gpt
	@parted -s $(IMAGE) mkpart primary 2048s 100%
	@echo ECHFS:: $(IMAGE)
	@echfs-utils -g -p0 $(IMAGE) quick-format 512
	@echfs-utils -g -p0 $(IMAGE) import scripts/limine.cfg limine.cfg
	@echfs-utils -g -p0 $(IMAGE) import $(TARGET) $(TARGET)
	@echo LIMINE:: $(IMAGE)
	@./limine/limine-install $(IMAGE)
	@echo ECHFS:: $(IMAGE)
	@echfs-utils -g -p0 $(IMAGE) import limine/limine.sys limine.sys
	@echo DONE!!

$(TARGET): $(OFILES)
	@echo LD:: $(TARGET)
	@$(CC) $(LDINTERNALFLAGS) $(OFILES) -o $@

%.o: %.c
	@echo CC:: $@
	@$(CC) $(CFLAGS) $(INTERNALCFLAGS) -c $< -o $@

%.o: %.asm
	@echo NASM:: $@
	@nasm -felf64 -o $@ $<

clean:
	@echo CLEAN::
	@rm $(OFILES) $(TARGET) $(IMAGE)

run:
	@echo RUN::
	@qemu-system-x86_64 -drive format=raw,file=$(IMAGE) -m 128M

setup:
	@echo Building and installing echFS utils
	@make -C echfs
	@make install -C echfs
	@echo Building limine
	@make -C limine
	@echo DONE::

all: clean $(IMAGE) run
