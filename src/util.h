#ifndef UTIL_H
#define UTIL_H

#include "def.h"
#include <stdbool.h>
#include <stdio.h>

/**
 *
 * param void
 * return
 */

int add_product(char *filename);

void print_product(Product *ptr);

int read(char *filename);

int view_all(char *filename);

bool search_all(char *filename, Product *data);

int update_product(Product *DAT, FILE *file_ptr);

#endif
