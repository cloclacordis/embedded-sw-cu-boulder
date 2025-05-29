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
  - `check` (optional): Clean, build, and generate `.asm` from `.c` and `.out` (HOST only).

- **File-specific targets**:  
  - `%.i`: Preprocessed source file (via `-E`);  
  - `%.asm`: Assembly output from C source (via `-S`);  
  - `%.o`: Object file (via compilation);  
  - `%.out.asm`: Disassembled output binary (via `objdump`).

---

### Example commands to test

```bash
make compile-all PLATFORM=HOST     # Compile all object files
make build PLATFORM=HOST           # Build and link executable
make clean PLATFORM=HOST           # Clean artifacts
make check PLATFORM=HOST           # Clean + build + generate asm (HOST only)
make main.o PLATFORM=MSP432        # Build single object file
make main.asm PLATFORM=HOST        # Generate assembly from source
make c1m2.out.asm PLATFORM=HOST    # Disassemble binary executable
```

