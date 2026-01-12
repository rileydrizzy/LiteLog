#ifndef DEF_H
#define DEF_H

#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define READ_MODE "rb"
#define WRITE_MODE "ab+"  
#define UPDATE_MODE "rb+"


#define W_ID 6
#define W_NAME 20
#define W_QTY 10
#define W_PRICE 10

/**
 * @brief Represents a single Product in the database.
 */
typedef struct
{
	int product_id; ///< Unique Product ID number
	char name[30];	///< Product Name
	int quantity; ///< Quantity of the Product available
	float price;	///< Price of the Product
} Product;

/**
* @brief
*
*/
typedef struct
{
	int total_no_prod; ///< Total Number of Product in the Inventory
	float total_val; ///< Total 
} Total;

#endif
