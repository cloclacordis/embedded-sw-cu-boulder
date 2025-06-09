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
# @file sources.mk
# @brief Makefile fragment listing sources and include paths per platform
#
# This Makefile fragment defines the source files and include paths used in
# the build process. It supports configuration for both HOST and MSP432
# embedded platform builds.
#
# This script was written as part of the Introduction to Embedded Systems
# Software and Development Environments course (University of Colorado Boulder).
#
# @author Timofei Alekseenko
# @date June 9, 2025 (modified)
#
#*****************************************************************************

# Defines source files and include directories per PLATFORM
ifeq ($(PLATFORM),HOST)

  # C source files for the HOST build
  SOURCES = \
    src/main.c \
    src/memory.c \
    src/stats.c \
    src/data.c \
    src/course1.c

  # Include path for HOST
  INCLUDES = \
    -Iinclude/common

else ifeq ($(PLATFORM),MSP432)

  # C source files for the MSP432 build
  SOURCES = \
    src/main.c \
    src/memory.c \
    src/stats.c \
    src/data.c \
    src/course1.c \
    src/system_msp432p401r.c \
    src/startup_msp432p401r_gcc.c \
    src/interrupts_msp432p401r_gcc.c

  # Include paths for MSP432
  INCLUDES = \
    -Iinclude/common \
    -Iinclude/msp432 \
    -Iinclude/CMSIS

else
  $(error PLATFORM must be set to HOST or MSP432)
endif

