#*****************************************************************************
# @file    Makefile
# @brief   Build script for Module3: Memory Segments Control & Analysis on MSP432
#
# This Makefile compiles sources into an ELF, generates a memory map (main.map),
# and supports several targets: all, disasm, symbols, and clean.
#
# Platform: MSP432 (arm-none-eabi-gcc + msp432p401r.lds)
#
# Author:  Timofei Alekseenko
# Date:    June 6, 2025
#
#*****************************************************************************

# Source files
SOURCES := main.c misc.c

# Compiler and flags
CC      := arm-none-eabi-gcc
CFLAGS  := -Wall -Werror -g -O0 -std=c99 \
           -mcpu=cortex-m4 -mthumb -march=armv7e-m \
           -mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS := -T msp432p401r.lds -Wl,-Map=main.map --specs=nosys.specs

# Size tool (optional)
SIZE    := arm-none-eabi-size

# Derived targets
OBJECTS := $(SOURCES:.c=.o)
ELF     := main.elf

# Phony targets
.PHONY: all disasm symbols clean

# 'all' builds the ELF and memory map
all: $(ELF)

# Link the final ELF and generate the map
$(ELF): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@
	@$(SIZE) $@

# Compile each .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Disassemble the ELF into human-readable assembly
disasm: $(ELF)
	arm-none-eabi-objdump -d $(ELF) > main.out.asm

# Extract symbol table from the ELF
symbols: $(ELF)
	arm-none-eabi-nm --print-size --radix=x $(ELF) > symbols.txt

# 'clean' removes all generated artifacts
clean:
	rm -f $(OBJECTS) $(ELF) main.map main.out.asm symbols.txt

