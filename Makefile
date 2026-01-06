# Makefile for compiling C code using the Clang compiler
CC = clang

CCFLAGS =  -Wall -Wextra -Wpedantic

SRC = src/main.c src/util.c

PROGRAM = litelog

$(PROGRAM): $(SRC)
	$(CC) $(CCFLAGS) $(SRC) -o $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

test: test.c
	$(CC) $(CCFLAGS) test.c -o test_program
	./test_program
