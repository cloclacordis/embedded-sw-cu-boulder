#*****************************************************************************
# @file    Makefile
# @brief   Build script for Module3: Memory Segments Control & Analysis on MSP432
#
# This Makefile compiles sources into an ELF, generates a memory map (main.map),
# and supports two main targets: all (build) and clean.
#
# Platform: MSP432 (arm-none-eabi-gcc + msp432p401r.lds)
#
# Author:  Timofei Alekseenko
# Date:    June 6, 2025
#
#*****************************************************************************

# Source files
SOURCES := main.c misc.c

# Compiler & flags
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
.PHONY: all clean

# 'all' builds the ELF
all: $(ELF)

# Link the final ELF & generate the map
$(ELF): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@
	@$(SIZE) $@

# Compile each .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 'clean' removes all generated artifacts
clean:
	rm -f $(OBJECTS) $(ELF) main.map

