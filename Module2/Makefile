#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************
#*****************************************************************************
# Project Module2: Build system for HOST and MSP432 platforms
#
# Use: make [TARGET] PLATFORM=HOST|MSP432
#
# Build Targets:
#      compile-all   - build all objects without linking
#      build         - build an executable file with a memory map, output the size
#      clean         - clean all generated artifacts
#      check         - clean + build + generate .asm from .c & .out (for HOST only)
#
#      %.i           - preprocessed output from sources
#      %.asm         - assembly output from sources (via -S flag)
#      %.o           - object output from sources
#      %.out.asm     - disassembly of final executable using objdump
#
# Platform Overrides:
#      PLATFORM      selects toolchain and flags:
#                    HOST    (gcc)
#                    MSP432  (arm-none-eabi-gcc + .lds linker script)
#
# This script was written as part of the Introduction to Embedded Systems
# Software and Development Environments course (University of Colorado Boulder).
#
# @author Timofei Alekseenko
# @date May 28, 2025
#
#*****************************************************************************

# Include platform-specific sources and include paths
include sources.mk

# Choose compiler, flags, and size tool based on PLATFORM
ifeq ($(PLATFORM),HOST)
	CC = gcc               
	PLATFORM_DEFS = -DHOST
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	LDFLAGS = # No special linker flags for HOST
	SIZE = size
    
else ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	PLATFORM_DEFS = -DMSP432
	CFLAGS = -Wall -Werror -g -O0 -std=c99 \
		 -mcpu=cortex-m4 -mthumb -march=armv7e-m \
		 -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
	LDFLAGS = -T msp432p401r.lds
	SIZE = arm-none-eabi-size
    
else
    $(error PLATFORM must be set to HOST or MSP432)
endif

# Preprocessor flags: include paths and platform defs
CPPFLAGS = $(INCLUDES) $(PLATFORM_DEFS)

# Derive object and dependency filenames from SOURCES
OBJECTS = $(SOURCES:.c=.o) # For each .c file, generate corresponding .o files
DEPS = $(SOURCES:.c=.d)    # For each .c file, generate corresponding .d files
OUT = c1m2.out             # Final output name
MAP = c1m2.map             # Final output name

# Include generated dependency files (if present)
-include $(DEPS)

# Preprocessed output from sources
%.i: %.c
	$(CC) $(CPPFLAGS) -E $< -o $@

# Assembly output from sources
%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $< -o $@

# Object output from sources
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

# Disassemble final executable into .asm
%.out.asm: %.out
	objdump -d $< > $@

# Proxy targets so `make main.o` works in project root
main.o:
	$(MAKE) src/main.o PLATFORM=$(PLATFORM)
main.asm:
	$(MAKE) src/main.asm PLATFORM=$(PLATFORM)
main.i:
	$(MAKE) src/main.i PLATFORM=$(PLATFORM)

### PHONY targets: compile-all, build, clean ###
# build all objects without linking
.PHONY: compile-all
compile-all: $(OBJECTS)

# Build an executable file with a memory map, output the size
.PHONY: build
build: $(OUT)
	$(SIZE) $<

$(OUT): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -Wl,-Map=$(MAP) -o $@

# Clean all generated artifacts
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(DEPS) $(OUT) $(MAP) \
	*.i *.asm src/*.asm src/*.i
	@echo "Clean complete"

# Clean, build & generate .asm from .c and .out (for HOST only)
.PHONY: check

ifeq ($(PLATFORM),HOST)
check:
	@echo "Checking HOST build..."
	$(MAKE) clean
	$(MAKE) build PLATFORM=HOST
	$(MAKE) src/main.asm PLATFORM=HOST
	$(MAKE) c1m2.out.asm PLATFORM=HOST
else
check:
	$(error check target is supported for HOST only)
endif

