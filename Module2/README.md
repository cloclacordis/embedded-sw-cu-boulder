## Cross-Platform Build System (x86_64 / MSP432)

This module implements a command-line build system using **GNU Make** and **GCC**, targeting both native (HOST) and embedded (MSP432) platforms.

### Features

- Cross-platform compilation support with a single Makefile
- Platform selection via `PLATFORM=HOST` or `PLATFORM=MSP432`
- Generates:
  - Preprocessed files (`*.i`)
  - Assembly output (`*.asm`)
  - Object files (`*.o`)
  - Executables (`*.out`)
  - Disassembly output (`*.out.asm`)
  - Memory map files

### Run

```bash
make [TARGET] PLATFORM=HOST|MSP432
```

### Available Targets

| Target        | Description                                                   |
| ------------- | ------------------------------------------------------------- |
| `compile-all` | Compile all object files without linking                      |
| `build`       | Compile and link, generate memory map                         |
| `clean`       | Remove all generated build artifacts                          |
| `check`       | Clean, build, and generate `.asm` and disassembly (HOST only) |

### Toolchain Requirements

* `make`
* `gcc` (for HOST builds)
* `arm-none-eabi-gcc`, `ld`, and `objdump` (for MSP432 builds)

### Platforms

| PLATFORM | Toolchain         | Target Architecture |
| -------- | ----------------- | ------------------- |
| HOST     | gcc               | x86_64              |
| MSP432   | arm-none-eabi-gcc | ARM Cortex-M4       |

### Notes

* MSP432 builds require a custom linker script (`*.lds`).
* Output size and memory usage are printed after linking.
* Intermediate outputs help with debugging and analysis.

---

This project was developed as part of the *Introduction to Embedded Systems Software and Development Environments* course (Module 2) by the University of Colorado Boulder.

