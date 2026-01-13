/**
 * @file util.h
 * @author Ladipo Ipadeola
 * @brief This file contains the function prototypes for the utility functions.
 * @version 0.1
 * @date 01-01-2026
 * @copyright Copyright (c) 2026
 */


#ifndef UTIL_H
#define UTIL_H

#include "def.h"
#include <stdbool.h>
#include <stdio.h>

/**
* @brief This function gets the user input and cleans it up.
* it removes the newline character and any extra characters.
* and also checks if the input is larger than the buffer.
* @param void
* @return void
*/

void get_clean_input(void);

/**
* @brief This function gets the product ID from the user.
* @param data_ptr A pointer to the Product structure.
* @return void
* @note This function is called in the add_product function.
 */

void get_prod_ID(Product *data_ptr);

/**
* @brief This function gets the product name from the user.
* @param data_ptr A pointer to the Product structure.
* @return void
* @note This function is called in the add_product function.
*/

void get_prod_name(Product *data_ptr);

/**
	* @brief This function gets the product quantity from the user.
	* @param data_ptr A pointer to the Product structure.
	* @return void
	* @note This function is called in the add_product function.
	*/
void get_prod_quantity(Product *data_ptr);

/**
	* @brief This function gets the product price from the user.
	* @param data_ptr A pointer to the Product structure.
	* @return void
	* @note This function is called in the add_product function.
	*/

void get_prod_price(Product *data_ptr);

/**
	* @brief This function prints the table header.
	* This includes the column names and the table borders.
	* Width of the columns are defined in the def.h file.
	* @param void
	* @return void
*/
void print_table_header(void);

/**
	* @brief This function prints the product row.
	* This includes the product ID, name, quantity and price.
	* Width of the columns are defined in the def.h file.
	* @param ptr A pointer to the Product structure.
	* @return void
	*/
void print_product_row(Product *ptr);

/**
	* @brief This function prints the table divider.
	* This includes the table borders.
	* Width of the columns are defined in the def.h file.
	* @param void
	* @return void
	*/
void print_table_divider(void);

/**
	* @brief This function prints the table footer.
	* This includes the total number of products and the total value of the products.
	* Width of the columns are defined in the def.h file.
	* @param ptr A pointer to the Total structure.
		* @return void
	*/
void print_table_footer(Total *ptr);

/**
	* @brief This function adds a new product to the inventory.
	* @param void
	* @return int EXIT_SUCCESS if the product is added successfully.
	*/

int add_product(void);

/**
	* @brief This function views all the products in the inventory.
	* @param void
	* @return int EXIT_SUCCESS if the products are viewed successfully.
	*/
int view_all(void);

/**
	* @brief This function opens a file.
	* @param filename A pointer to the file name.
	* @param mode A pointer to the file mode.
	* @return FILE* A pointer to the file.
	*/
FILE *open_file(const char *filename, const char *mode);

/**
	* @brief This function searches for a product in the inventory.
	* @param void	
	* @return void
	*/
void search_product(void);

/**
	* @brief This performs the search operation on the file.
	* @param file_ptr A pointer to the file.
	* @return bool true if the product is found, false otherwise.
	*/
bool search_func(FILE *file_ptr, ...);

// TODO: Add documentation for this function
/**	
	* @brief This function updates the product details.
	* @param DAT A pointer to the Product structure.
	* @param file_ptr A pointer to the file.
	* @return int EXIT_SUCCESS if the product is updated successfully.
	*/
int update_product_func(Product *DAT, FILE *file_ptr);

void update_product(void);

void delete_product(void);

void clean_up(void);

#endif
