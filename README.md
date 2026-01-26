# LiteLog — Minimal Inventory Manager

LiteLog is a small command-line inventory management program written in C. It provides a compact example of a file-backed inventory database (binary format) and a simple text menu for adding, viewing, searching, updating, and deleting products.

**Key points**
- Data is persisted in a binary file (`inventory.dat`) by default.
- Uses a simple fixed-size `Product` record (ID, name, quantity, price).
- Demonstrates safe input handling, file I/O, and basic table-style output on the terminal.

**Build requirements**
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
- `5` — Delete a product: removes the matching product by rewriting the file without it.
- `6` — Exit the program.

**Implementation details**
- Data file: default filename is `inventory.dat` (see `src/main.c`). A temporary file `temp.dat` is used for safe deletes.
- Record: `Product` struct (defined in `src/def.h`) contains `product_id`, `name[30]`, `quantity`, and `price`.
- Input: reading and sanitizing user input is implemented in `src/util.c` to avoid leftover newline and buffer overflow issues.
- Table output: `util.c` prints a simple ASCII table with column widths defined in `src/def.h`.
- Validation: Checks for duplicate product IDs when adding new products to ensure data integrity.

**Files of interest**
- `src/main.c` — program entrypoint and main menu loop.
- `src/util.c` — utility functions: add, view, search, update, delete, and table printing.
- `src/util.h` — function prototypes and API.
- `src/def.h` — constants, color macros, and `Product`/`Total` type definitions.
- `Makefile` — build and run targets.

**Contributing**
- Small improvements and bug fixes are welcome. Open an issue or a pull request.

**License**

See the `LICENSE` file in the repository root for licensing details.
