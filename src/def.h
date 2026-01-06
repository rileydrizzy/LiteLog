#ifndef DEF_H
#define DEF_H

/**
 * @brief Represents a single Product in the database.
 */
typedef struct
{
	int product_id; ///< Unique Product ID number
	char name[50];  ///< Product Name
	short quantity; ///< Quantity of the Product available
	float price;    ///< Price of the Product
} Product;


typedef enum
{
	id,
	name,
	quantity,
	price,
} product_index;

#endif
