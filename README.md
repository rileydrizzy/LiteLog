LiteLog — Minimal Inventory Manager

LiteLog is a small command-line inventory management program written in C. It provides a compact example of a file-backed inventory database (binary format) and a simple text menu for adding, viewing, searching, updating, and deleting products.

Key points
- Data is persisted in a binary file (`inventory.dat`) by default.
- Uses a simple fixed-size `Product` record (ID, name, quantity, price).
- Demonstrates safe input handling, file I/O, and basic table-style output on the terminal.

Build requirements
- A C compiler (the `Makefile` uses `clang` by default; `gcc` works too).
- POSIX-compatible shell to run `make` targets.

Build and run
From the repository root:

```bash
make       # builds the `litelog` executable (uses clang by default)
make run   # builds (if needed) and runs the program
```

Or run the executable directly after building:

```bash
./litelog
```

Usage (interactive)
When started the program shows a numbered menu:

- `1` — Add new product: prompt for product ID, name, quantity, and price; saves to `inventory.dat`.
- `2` — View all products: reads `inventory.dat` and prints a table of products with totals.
- `3` — Search for a product: prompt for product ID and shows the matching record.
- `4` — Update product details: search by ID, then choose which field to update.
- `5` — Delete a product: removes the matching product by rewritting the file without it.
- `6` — Exit the program.

Implementation details
- Data file: default filename is `inventory.dat` (see `src/main.c`). A temporary file `temp.dat` is used for safe deletes.
- Record: `Product` struct (defined in `src/def.h`) contains `product_id`, `name[30]`, `quantity`, and `price`.
- Input: reading and sanitizing user input is implemented in `src/util.c` to avoid leftover newline and buffer overflow issues.
- Table output: `util.c` prints a simple ASCII table with column widths defined in `src/def.h`.

Files of interest
- `src/main.c` — program entrypoint and main menu loop.
- `src/util.c` — utility functions: add, view, search, update, delete, and table printing.
- `src/util.h` — function prototypes and API.
- `src/def.h` — constants, color macros, and `Product`/`Total` type definitions.
- `Makefile` — build and run targets.

Author / Maintainer
- Original source author: Ladipo Ipadeola (see file headers in `src`).
- Repository owner / maintainer: rileydrizzy

Contributing
- Small improvements and bug fixes are welcome. Open an issue or a pull request.

Notes and possible enhancements
- Add more robust validation for duplicate product IDs and numeric input ranges.
- Add command-line arguments to specify an alternate data file.
- Add CSV import/export for easier data interchange.
- Add unit tests or a small test harness to validate file operations.

License
See the `LICENSE` file in the repository root for licensing details.
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
