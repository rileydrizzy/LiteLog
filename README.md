# LiteLog

LiteLog is a small, lightweight C logging demonstration and utility. It provides a compact example of how to add a simple logging facility to a C program, with a minimal API and example usage in `src/main.c`.

**Features**
- Minimal logging helpers implemented in plain C.
- Easy to read and adapt for embedding into small projects or learning purposes.

**Requirements**
- A C compiler (project uses `clang` by default; `gcc` should also work).
- POSIX-compatible shell to run the included `Makefile` targets.

**Build**
From the repository root run:

```bash
make
```

This produces the `litelog` executable.

You can also run the program directly via the provided Make target:

```bash
make run
```

**Usage**
After building, run the executable:

```bash
./litelog
```

The example entrypoint is `src/main.c` and the logging helpers are implemented in `src/util.c` with headers in `src/util.h` and `src/def.h`.

**Repository layout**
- `src/` — source code
  - `main.c` — example program demonstrating logging usage
  - `util.c` — logging helper implementations
  - `util.h` — logging helper declarations
  - `def.h` — macros and definitions used by the project
- `Makefile` — build and run targets
- `LICENSE` — project's license

**Contributing**
Contributions are welcome. Open an issue or submit a pull request with changes or improvements. For small projects like this, keep changes focused and add short descriptions of intent.

**License**
This project includes a `LICENSE` file in the repository root. Check it for licensing details.

**Notes / Next steps**
- You can adapt the logging helpers for different log levels, output formats, or to write to files. If you'd like, I can add examples showing log levels, configurable output, or a simple test harness.
