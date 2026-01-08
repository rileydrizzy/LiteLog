#include "util.h"
// #include "def.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// extern char user_input[3];
extern char FILENAME[] = "inventory.dat";
extern char BUFFER[60];
extern Product ITEM;
extern unsigned short user_choice;

void print_product(Product *ptr)
{
    // Table Header
    printf("%-5s %-25s %-10s %-10s \n", "|ID|", "|Product Name|", "|Product Quantity|", "|Product Price|");
    printf("---------------------------------------------\n");
    printf("%-5d %-25s %-5d %-2f \n", ptr->product_id, ptr->name, ptr->quantity, ptr->price);
}

int add_product(void)
{
    Product *ptr = &ITEM;
    puts("Enter Product ID:");
    if (fgets(BUFFER, sizeof(BUFFER), stdin))
    {
        if (sscanf(BUFFER, "%d", &ITEM.product_id) != EOF)
        {
            printf("Product ID: %d\n", ptr->product_id);
        }
    }

    puts("Enter Product Name:");
    if (fgets(ITEM.name, sizeof(ITEM.name), stdin) != NULL)
    {
        printf("Product ID: %s\n", ptr->name);
    }

    puts("Enter Product Quantity:");
    // BUFFER[0] = '\0';
    if (fgets(BUFFER, sizeof(BUFFER), stdin))
    {
        if (sscanf(BUFFER, "%hd", &ITEM.quantity) != EOF)
        {
            printf("Product ID: %hd\n", ptr->quantity);
        }
    }
    puts("Enter Product Price:");
    if (fgets(BUFFER, sizeof(BUFFER), stdin))
    {
        if (sscanf(BUFFER, "%f", &ITEM.price) != EOF)
        {
            printf("Product ID: %f\n", ptr->price);
        }
    }
    // TODO Write data into file
    FILE *file = fopen(FILENAME, "ab");
    if (!file)
    {
        // Handle error
        perror("Error");
        return EXIT_FAILURE;
    }
    fwrite(&ITEM, sizeof(Product), 1, file);
    fclose(file);
    puts("Done");

    return EXIT_SUCCESS;
}

int view_all(void)
{
    FILE *file = fopen(FILENAME, "rb");
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

FILE *open_file()
{
    FILE *file = fopen(FILENAME, "rb+");
    if (!file)
    { // Handle error
        perror("Error");
        return NULL;
    }
    return file;
}

bool search_item() // FILE *file_ptr)
{
    int target_id;
    bool found = false;
    printf("Enter the Product ID");
    fgets(BUFFER, sizeof(BUFFER), stdin);
    sscanf(BUFFER, "%d", &target_id);
    FILE *file_ptr = open_file();
    while (fread(&ITEM, sizeof(Product), 1, file_ptr) == 1)
    {
        if (ITEM.product_id == target_id)
        {
            puts("Found");
            found = true;
            return found;
        }
    }
    puts("Not found");
close_file:
    fclose(file_ptr);
    return found;
}

int update_product(Product *DAT, FILE *file_ptr)
{

    fseek(file_ptr, -sizeof(Product), SEEK_CUR);
    if (fwrite(&DAT, sizeof(Product), 1, file_ptr) != 1)
    {
        printf("Unsuccessful");
    }
    fclose(file_ptr);
    return EXIT_SUCCESS;
}

// TODO ASK THE USER WHAT  THEY WHAT TO UPDATE nAME, Q AND PRICE

void update_menu_display()
{
    bool result = search_item();
    if (!result)
    {
        return;
    }
    printf("Enter the number below to select the Product detail \n you want to update");
    printf("1. Product Name \n");
    printf("2. Product Quantity \n");
    printf("3. Product Price \n");
    fgets(BUFFER, sizeof(BUFFER), stdin);
    sscanf(BUFFER, "%d", &user_choice);
    switch (user_choice)
    {
    case 1:
        // Name
        printf("Enter the Product name");
        fgets(BUFFER, sizeof(BUFFER), stdin);
        // ITEM.name =
        update_product(&ITEM);
         break;
    case 2:
        //
        //printf break;
    case 3:
        // Price
        break;

    default:
        break;
    }
}





    // BUFFER[0] = '\0';
get_prod_qauntity(Product *data_ptr){
    if (fgets(BUFFER, sizeof(BUFFER), stdin)){
        if (sscanf(BUFFER, "%hd", &data_ptr->quantity) != EOF)
        {
            printf("Product ID: %hd\n", ptr->quantity);
        }
    }

