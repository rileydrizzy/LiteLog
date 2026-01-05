#include <stdlib.h>
#include <stdio.h>
#include "util.h"

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
    name,
    quantity,
    price,
} product_index;

int add_product(void)
{
    Product new_product;
    Product *ptr = &new_product;
    char BUFFER[60];
    puts("Enter Product ID: ");
    if fgets(BUFFER, sizeof(BUFFER), stdin)

    return EXIT_SUCCESS;
}
