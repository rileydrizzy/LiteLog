/**
 * @file def.h
 * @author Ladipo Ipadeola
 * @brief This file contains the definitions for the inventory management system.
 * @version 0.1
 * @date 01-01-2026
 * @copyright Copyright (c) 2026
 */

#ifndef DEF_H
#define DEF_H

// Color codes for the terminal
#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define READ_MODE "rb"
#define WRITE_MODE "ab+"
#define UPDATE_MODE "rb+"
#define MENU_EXIT_OPTION 7

// Width of the columns
#define W_ID 6
#define W_NAME 20
#define W_QTY 10
#define W_PRICE 10

#define BUFFER_SIZE 30
#define MAX_ID_DIGITS 5

/**
 * @brief Represents a single Product in the database.
 * This structure holds the details of a product, including its ID, name, quantity, and price.
 * It is used to store and retrieve product information from the database.
 * @note The name field is limited to 30 characters.
 * @note The price field is a floating-point number.
 * @note The quantity field is an integer.
 * @note The product_id field is an integer.
 */
typedef struct
{
	int product_id;			///< Unique Product ID number
	char name[BUFFER_SIZE]; ///< Product Name
	int quantity;			///< Quantity of the Product available
	float price;			///< Price of the Product
} Product;

/**
 * @brief
 * This structure holds the total number of products and the total value of the products.
 * It is used to store and retrieve the total number of products and the total value of the products.
 * @note The total_no_prod field is an integer.
 * @note The total_val field is a floating-point number.
 */
typedef struct
{
	int total_no_prod; ///< Total Number of Product in the Inventory
	float total_val;   ///< Total Value of the Products
} Total;

#endif
