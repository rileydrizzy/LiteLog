#ifndef DEF_H
#define DEF_H

#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

/**
 * @brief Represents a single Product in the database.
 */
typedef struct
{
	int product_id; ///< Unique Product ID number
	char name[50];	///< Product Name
	short quantity; ///< Quantity of the Product available
	float price;	///< Price of the Product
} Product;

typedef enum
{
	id,
	name,
	quantity,
	price,
} product_index;

#endif
