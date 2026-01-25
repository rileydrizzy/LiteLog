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
 * @brief Gets user input and cleans it up.
 *
 * Reads a line from stdin into the provided buffer.
 * It removes the trailing newline character and flushes stdin if the input
 * exceeds the buffer size.
 *
 * @param out_buffer The buffer to store the input.
 * @param size The size of the buffer.
 */
void get_clean_input(char *out_buffer, int size);

/**
 * @brief Prompts the user for the Product ID.
 *
 * Reads the ID from standard input and stores it in the provided Product structure.
 *
 * @param data_ptr A pointer to the Product structure.
 * @param out_buffer Buffer to use for input reading.
 */
void get_prod_ID(char *out_buffer, Product *data_ptr);

/**
 * @brief Prompts the user for the Product Name.
 *
 * Reads the name from standard input and stores it in the provided Product structure.
 *
 * @param data_ptr A pointer to the Product structure.
 * @param out_buffer Buffer to use for input reading.
 */
void get_prod_name(char *out_buffer, Product *data_ptr);

/**
 * @brief Prompts the user for the Product Quantity.
 *
 * Reads the quantity from standard input and stores it in the provided Product structure.
 *
 * @param data_ptr A pointer to the Product structure.
 * @param out_buffer Buffer to use for input reading.
 */
void get_prod_quantity(char *out_buffer, Product *data_ptr);

/**
 * @brief Prompts the user for the Product Price.
 *
 * Reads the price from standard input and stores it in the provided Product structure.
 *
 * @param data_ptr A pointer to the Product structure.
 * @param out_buffer Buffer to use for input reading.
 */
void get_prod_price(char *out_buffer, Product *data_ptr);

/**
 * @brief Prints the table header.
 *
 * Displays the column names (ID, Name, Quantity, Price) and the top border of the table.
 * Column widths are defined in def.h.
 */
void print_table_header(void);

/**
 * @brief Prints a single product row.
 *
 * Displays the details of a product formatted within the table columns.
 *
 * @param ptr A pointer to the Product structure containing the data to print.
 */
void print_product_row(Product *ptr);

/**
 * @brief Prints a table divider line.
 *
 * Used to separate headers, rows, or footers in the table output.
 */
void print_table_divider(void);

/**
 * @brief Prints the table footer with totals.
 *
 * Displays the total number of products and the total value of the inventory.
 *
 * @param ptr A pointer to the Total structure containing the calculated totals.
 */
void print_table_footer(Total *ptr);

/**
 * @brief Adds a new product to the inventory.
 *
 * Prompts the user for product details and appends the new record to the file.
 *
 * @param out_buffer Buffer to use for input reading.
 * @param data_ptr Pointer to a Product structure to hold temporary data.
 * @return int EXIT_SUCCESS on success.
 */
int add_product(char *out_buffer, Product *data_ptr);

/**
 * @brief Views all products in the inventory.
 *
 * Reads the inventory file and displays all products in a formatted table.
 * Also calculates and displays totals.
 *
 * @param data_ptr Pointer to a Product structure to hold read data.
 * @return int EXIT_SUCCESS on success.
 */
int view_all(Product *data_ptr);

/**
 * @brief Opens a file with the specified mode.
 *
 * If the file does not exist and is opened for reading, it attempts to create it.

 * @param filename The name of the file to open.
 * @param mode The mode string (e.g., "rb", "ab+").
 * @return FILE* A pointer to the opened file stream, or NULL on failure.
 */
FILE *open_file(const char *filename, const char *mode);

/**
 * @brief Searches for a product and displays it.
 *
 * Uses search_func to find a product by ID and prints the result in a table format.
 *
 * @param out_buffer Buffer to use for input reading.
 * @param data_ptr Pointer to a Product structure to hold the found data.
 */
void search_product(char *out_buffer, Product *data_ptr);

/**
 * @brief Performs the search operation on the file.
 *
 * Prompts the user for a Product ID, then scans the file for a matching record.
 *
 * @param file_ptr A pointer to the open file stream.
 * @param out_buffer Buffer to use for input reading.
 * @param data_ptr A pointer to the Product structure to populate.
 * @return true if the product is found, false otherwise.
 */
bool search_func(FILE *file_ptr, char *out_buffer, Product *data_ptr);

/**
 * @brief Updates the product details in the file.
 *
 * @param data_ptr A pointer to the Product structure containing updated info.
 * @param file_ptr A pointer to the file stream (must be in update mode).
 * @return int EXIT_SUCCESS on success.
 */
int update_product_func(Product *data_ptr, FILE *file_ptr);

/**
 * @brief Orchestrates the product update process.
 *
 * Prompts for an ID, searches for the product, and allows the user to
 * update specific fields (Name, Quantity, Price).
 *
 * @param out_buffer Buffer to use for input reading.
 * @param data_ptr Pointer to a Product structure to hold data.
 */
void update_product(char *out_buffer, Product *data_ptr);

/**
 * @brief Deletes a product from the inventory.
 *
 * @param out_buffer Buffer to use for input reading.
 * @param data_ptr Pointer to a Product structure to hold data.
 */
void delete_product(char *out_buffer, Product *data_ptr);

/**
 * @brief Resets buffers and structures.
 *
 * Clears the input buffer and the Product structure pointed to by data_ptr.
 *
 * @param input_buffer The buffer to clear.
 * @param data_ptr The Product structure to clear.
 */
void clean_up(char *input_buffer, Product *data_ptr);

/**
 * @brief Checks if a Product ID already exists in the inventory.
 *
 * @param data_ptr Pointer to the Product structure containing the ID to check.
 * @return true if the ID exists, false otherwise.
 */
bool check_prod_id_avail(Product *data_ptr);

#endif
