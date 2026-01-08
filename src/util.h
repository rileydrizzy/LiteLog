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

void print_product(Product *ptr);

int add_product(void);

int view_all(void);

FILE *open_file();

bool search_item();

int update_product(Product *DAT, FILE *file_ptr);

void update_menu_display();

#endif
