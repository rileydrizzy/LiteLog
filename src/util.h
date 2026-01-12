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

/**
 *
 * param void
 * return
 */

void get_clean_input(void);
void get_prod_name(Product *data_ptr);

void get_prod_quantity(Product *data_ptr);

void get_prod_price(Product *data_ptr);

void print_table_header(void);

void print_product_row(Product *ptr);

void print_table_footer(Total *ptr);

int add_product(void);

int view_all(void);

FILE *open_file(const char *filename, const char *mode);

void search_product(void);

bool search_func(FILE *file_ptr, ...);

int update_product_func(Product *DAT, FILE *file_ptr);

void update_product(void);

void delete_product(void);

void clean_up(void);

#endif
