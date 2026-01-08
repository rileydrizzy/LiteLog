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


void get_prod_ID(Product *data_ptr);

void get_prod_name(Product *data_ptr);

void get_prod_quantity(Product *data_ptr);

void get_prod_price(Product *data_ptr);

void print_product(Product *ptr);

int add_product(void);

int view_all(void);

FILE *open_file(const char* mode);

void search_product(void);

bool search_func(FILE* file_ptr, ...);

int update_product_func(Product *DAT, FILE *file_ptr);

void update_product();

#endif
