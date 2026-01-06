# Makefile for compiling C code using the Clang compiler
CC = gcc

CCFLAGS =  -Wall -Wextra -Wpedantic

SRC = src/main.c src/util.c 

PROGRAM = litelog

$(PROGRAM): $(SRC)
	$(CC) $(CCFLAGS) $(SRC) -o $(PROGRAM)

run:
	./$(PROGRAM)

