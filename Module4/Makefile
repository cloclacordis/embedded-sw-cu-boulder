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
# Project Module4: Expanded Build System and Memory Manipulation
#
# Usage: make [build|clean] PLATFORM=HOST|MSP432 [VERBOSE=1]
#
# Targets:
#   build       - compile all sources and link into executable (course1.out)
#   clean       - remove object files, executables, and intermediate outputs
#
# Platforms:
#   PLATFORM=HOST    => gcc, HOST simulation
#   PLATFORM=MSP432  => arm-none-eabi-gcc, link with msp432p401r.lds
#
# Flags:
#   VERBOSE=1   => enable debug printing in stats module
#   COURSE1=1   => include course1 demo application entry in main
#
# This script was written as part of the Introduction to Embedded Systems
# Software and Development Environments course (University of Colorado Boulder).
#
# @author Timofei Alekseenko
# @date June 9, 2025 (modified)
#
#*****************************************************************************

include sources.mk

# Platform-specific configurations
ifeq ($(PLATFORM),HOST)
  CC = gcc
  PLATFORM_DEFS = -DHOST $(if $(VERBOSE),-DVERBOSE) $(if $(COURSE1),-DCOURSE1)
  CFLAGS = -Wall -Werror -g -O0 -std=c99
  LDFLAGS =
  SIZE = size
else ifeq ($(PLATFORM),MSP432)
  CC = arm-none-eabi-gcc
  PLATFORM_DEFS = -DMSP432 $(if $(VERBOSE),-DVERBOSE) $(if $(COURSE1),-DCOURSE1)
  CFLAGS = -Wall -Werror -g -O0 -std=c99 \
           -mcpu=cortex-m4 -mthumb -march=armv7e-m \
           -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
           --specs=nosys.specs
  LDFLAGS = -T msp432p401r.lds
  SIZE = arm-none-eabi-size
else
  $(error PLATFORM must be HOST or MSP432)
endif

# Filter out MSP432-specific files for HOST platform
ifeq ($(PLATFORM),HOST)
  SOURCES := $(filter-out src/interrupts_msp432p401r_gcc.c, $(SOURCES))
  SOURCES := $(filter-out src/startup_msp432p401r_gcc.c, $(SOURCES))
  SOURCES := $(filter-out src/system_msp432p401r.c, $(SOURCES))
endif

CPPFLAGS = $(INCLUDES) $(PLATFORM_DEFS)
OBJECTS = $(SOURCES:.c=.o)
OUT = course1.out

# Default target
.PHONY: build
build: $(OUT)

$(OUT): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	$(SIZE) $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Special rule for MSP432 interrupt handler
src/interrupts_msp432p401r_gcc.o: src/interrupts_msp432p401r_gcc.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -mgeneral-regs-only -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(OUT) *.i *.asm *.d

.PHONY: test
test:
	$(MAKE) clean
	$(MAKE) PLATFORM=HOST COURSE1=1 VERBOSE=1
