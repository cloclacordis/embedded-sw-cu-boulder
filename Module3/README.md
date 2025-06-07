## Memory Segments Control & Analysis on MSP432

The project focuses on understanding memory segment layout on the **MSP432** microcontroller (**Cortex-M4F**).

### Overview

In this project, the goal was to build a **Makefile** that:
- Compiles source files (`main.c`, `misc.c`) for the MSP432 platform.
- Links the files using a custom linker script (`msp432p401r.lds`) to produce the final ELF executable.
- Generates a **memory map** (`main.map`), a **disassembly** of the ELF file (`main.out.asm`), and a **symbol table** (`symbols.txt`).

The project also involves analyzing each symbol's location, access permissions, and lifetime to ensure efficient memory use on the microcontroller.

### Project Details

- **Platform:** MSP432 (Cortex-M4F)
- **Languages:** Embedded C & Bash
- **Tools:** `arm-none-eabi-gcc`, `make`, `nm`, `objdump`
- **Memory analysis tasks:** 
    - Identifying memory segments (e.g., `.text`, `.data`, `.bss`, `.rodata`).
    - Assigning symbols to appropriate segments and analyzing access (read/write) permissions and lifetimes.

### Getting Started

Clone this repository:

```bash
git clone https://github.com/cloclacordis/embedded-sw-cu-boulder.git
cd embedded-sw-cu-boulder/Module3
```

### Building the Project

To compile the project and generate the ELF file, run:

```bash
make
```
> or: `make all`.

This will compile the source files (`main.c`, `misc.c`), link them into the `main.elf` file, and generate the memory map (`main.map`).

### Additional Makefile Targets

* **Generate the symbol table**:

```bash
make symbols
```

* **Disassemble the ELF**:

```bash
make disasm
```

### Files in this repository (Module3):

* `main.c` — Main application file for the MSP432
* `misc.c` — Miscellaneous functions for memory manipulation
* `msp432p401r.lds` — Linker script for the MSP432
* `Makefile` — Build script to compile and link the project
* `main.map` — Memory map of the compiled ELF
* `symbols.txt` — Extracted symbol table
* `main.out.asm` — Disassembly of the ELF file

### References

For a detailed explanation of the memory segment analysis, please check my [DevJournal](https://github.com/cloclacordis/embedded-sw-cu-boulder/blob/main/Module3/DEVJOUR.md).

---

This project was developed as part of the *Introduction to Embedded Systems Software and Development Environments* course (Module 3) by the University of Colorado Boulder.
