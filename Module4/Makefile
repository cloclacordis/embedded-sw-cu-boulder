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

ifeq ($(PLATFORM),HOST)
  CC            = gcc
  PLATFORM_DEFS = -DHOST -DCOURSE1 $(if $(VERBOSE),-DVERBOSE)
  CFLAGS        = -Wall -Werror -g -O0 -std=c99
  SIZE          = size
else ifeq ($(PLATFORM),MSP432)
  CC            = arm-none-eabi-gcc
  PLATFORM_DEFS = -DMSP432 -DCOURSE1 $(if $(VERBOSE),-DVERBOSE)
  CFLAGS        = -Wall -Werror -g -O0 -std=c99 \
                  -mcpu=cortex-m4 -mthumb -march=armv7e-m \
                  -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
                  -mgeneral-regs-only --specs=nosys.specs
  LDFLAGS       = -T msp432p401r.lds
  SIZE          = arm-none-eabi-size
else
  $(error PLATFORM must be set to HOST or MSP432)
endif

CPPFLAGS = $(INCLUDES) $(PLATFORM_DEFS)
OBJECTS  = $(SOURCES:.c=.o)
OUT      = course1.out

.PHONY: build clean

build: $(OBJECTS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ $(LDFLAGS) -o $(OUT)
	$(SIZE) $(OUT)

clean:
	rm -f $(OBJECTS) $(OUT) *.i *.asm

