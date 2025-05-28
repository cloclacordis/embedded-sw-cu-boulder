<!--
@file TEST4MAKE.md
@brief Makefile testing guide for the HOST and MSP432 platform switcer

This guide describes how to test Makefile targets required for the build system, including optional targets and individual file rules.

This document was written as part of the Introduction to Embedded Systems Software and Development Environments course (University of Colorado Boulder).

@author Timofei Alekseenko  
@date May 28, 2025
-->

## Makefile Testing Guide

### Overview

This guide explains how to test the provided Makefile targets for both `HOST` and `MSP432` platforms.

### Testing Instructions

The following targets must be tested according to the assignment requirements:  
- **PHONY targets**:  
  - `compile-all`: Build all object files without linking;  
  - `build`: Build an executable file with a memory map, output the size;  
  - `clean`: Clean all generated artifacts;  
  - `check` (optional): Clean, build, and generate `.asm` from `.c` & `.out` (for HOST only).

- **Individual file targets**:  
  - `%.i`: Preprocessed output from sources;  
  - `%.asm`: Assembly output from sources (via `-S` flag);  
  - `%.o`: Object output from sources;  
  - `%.out.asm`: Disassembly of final executable using `objdump`.

---

### Example commands to test

```bash
make compile-all PLATFORM=HOST     # compile all objects without linking
make build PLATFORM=HOST           # build executable and show size
make clean PLATFORM=HOST           # clean all build artifacts
make check PLATFORM=HOST           # optional check target for HOST
make main.o PLATFORM=MSP432        # compile single object file
make main.asm PLATFORM=HOST        # generate assembly file
make c1m2.out.asm PLATFORM=HOST    # disassemble final executable
```

