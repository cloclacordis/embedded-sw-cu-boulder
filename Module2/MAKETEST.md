<!--
@file MAKETEST.md
@brief Makefile testing guide for cross-platform build system (HOST/MSP432)

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
  - `compile-all`: Compile all object files without linking;  
  - `build`: Compile, link, and generate memory map; output binary size;  
  - `clean`: Remove all generated artifacts;  
  - `check` (optional): Clean, build, generate `.asm` from `.c` and `.out`, and disassembly via `objdump`.

- **File-specific targets**:  
  - `%.i`: Preprocessed source file (via `-E`);  
  - `%.asm`: Assembly output from C source (via `-S`);  
  - `%.o`: Object file (via compilation);  
  - `%.out.asm`: Disassembled output binary (via `objdump`).

---

### Example commands to test

```bash
make compile-all PLATFORM=HOST        # Compile all object files (HOST)
make compile-all PLATFORM=MSP432      # Compile all object files (MSP432)

make build PLATFORM=HOST              # Build and link executable (HOST)
make build PLATFORM=MSP432            # Build and link executable (MSP432)

make clean PLATFORM=HOST              # Clean all artifacts (HOST)
make clean PLATFORM=MSP432            # Clean all artifacts (MSP432)

make check PLATFORM=HOST              # Clean + build + generate asm + disassemble (HOST)
make check PLATFORM=MSP432            # Clean + build + generate asm + disassemble (MSP432)

make main.i PLATFORM=HOST             # Generate preprocessed output from src/main.c (HOST)
make main.i PLATFORM=MSP432           # Generate preprocessed output from src/main.c (MSP432)

make main.asm PLATFORM=HOST           # Generate assembly from src/main.c (HOST)
make main.asm PLATFORM=MSP432         # Generate assembly from src/main.c (MSP432)

make main.o PLATFORM=HOST             # Build single object file src/main.o (HOST)
make main.o PLATFORM=MSP432           # Build single object file src/main.o (MSP432)

make c1m2.out.asm PLATFORM=HOST       # Disassemble final executable (HOST)
make c1m2.out.asm PLATFORM=MSP432     # Disassemble final executable (MSP432)
```

