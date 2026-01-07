#include "util.h"
#include <stdlib.h>
#include <stdio.h>
#include "def.h"

void print_product(Product *ptr)
{
    // Table Header
    printf("%-5s %-25s %-10s %-10s \n", "|ID|", "|Product Name|", "|Product Quantity|", "|Product Price|");
    printf("---------------------------------------------\n");
    printf("%-5d %-25s %-5d %-2f \n", ptr->product_id, ptr->name, ptr->quantity, ptr->price);
}

int add_product(char *filename)
{
    Product new_product;
    Product *ptr = &new_product;
    char BUFFER[60];
    puts("Enter Product ID:");
    if (fgets(BUFFER, sizeof(BUFFER), stdin))
    {
        if (sscanf(BUFFER, "%d", &ptr->product_id) != EOF)
        {
            printf("Product ID: %d\n", ptr->product_id);
        }
    }

    puts("Enter Product Name:");
    if (fgets(new_product.name, sizeof(new_product.name), stdin) != NULL)
    {
        printf("Product ID: %s\n", ptr->name);
    }

    puts("Enter Product Quantity:");
    // BUFFER[0] = '\0';
    if (fgets(BUFFER, sizeof(BUFFER), stdin))
    {
        if (sscanf(BUFFER, "%hd", &ptr->quantity) != EOF)
        {
            printf("Product ID: %hd\n", ptr->quantity);
        }
    }
    puts("Enter Product Price:");
    if (fgets(BUFFER, sizeof(BUFFER), stdin))
    {
        if (sscanf(BUFFER, "%f", &ptr->price) != EOF)
        {
            printf("Product ID: %f\n", ptr->price);
        }
    }
    // TODO Write data into file
    FILE *file = fopen(filename, "ab");
    if (!file)
    {
        // Handle error
        perror("Error");
        return EXIT_FAILURE;
    }
    fwrite(&new_product, sizeof(Product), 1, file);
    fclose(file);
    puts("Done");

    return EXIT_SUCCESS;
}

int view_all(char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        // Handle error
        perror("Error");
        return EXIT_FAILURE;
    }
    Product data;
    puts("Starting read");
    printf("%-5s %-15s %-10s %-10s \n", "|ID|", "|Product Name|", "|Product Quantity|", "|Product Price|");
    printf("----------------------------------------------------------\n");
    while (fread(&data, sizeof(Product), 1, file))
    {
        printf("%-5d %-15s %-10d %-2f \n", data.product_id, data.name, data.quantity, data.price);
    }
    fclose(file);
    return EXIT_SUCCESS;
}
