#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int product_id; ///< Unique Product ID number
    char name[50];  ///< Product Name
    short quantity; ///< Quantity of the Product available
    float price;    ///< Price of the Product
} Product;

int main(void)
{
    Product data;
    data.product_id = 5448;
    printf("%d\n", data.product_id);
    return EXIT_SUCCESS;
}
