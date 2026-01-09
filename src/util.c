#include "util.h"
#include "def.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

// extern char user_input[3];
extern const char *FILENAME;
extern char BUFFER[60];
extern Product ITEM;
extern int user_choice;


void get_prod_ID(Product *data_ptr){
    puts("Enter Product ID:");
    if (fgets(BUFFER, sizeof(BUFFER), stdin))
    {
        if (sscanf(BUFFER, "%d", &data_ptr->product_id) != EOF)
        {
            printf("Product ID: %d\n", data_ptr->product_id);
        }
    }
}
void get_prod_name(Product *data_ptr){
    puts("Enter Product Name:");
    if (fgets(data_ptr->name, sizeof(data_ptr->name), stdin) != NULL){
        printf("Product Name: %s\n", data_ptr->name);
    }}
void get_prod_quantity(Product *data_ptr){
    puts("Enter Product Quantity:");
    if (fgets(BUFFER, sizeof(BUFFER), stdin)){
        if (sscanf(BUFFER, "%hd", &data_ptr->quantity) != EOF)
        {
            printf("Product ID: %hd\n", data_ptr->quantity);
        }
    }}
void get_prod_price(Product *data_ptr){
    puts("Enter Product Price:");
    if (fgets(BUFFER, sizeof(BUFFER), stdin))
    {
        if (sscanf(BUFFER, "%f", &data_ptr->price) != EOF)
        {
            printf("Product ID: %f\n", data_ptr->price);
        }
    }}

void print_product(Product *ptr)
{
    // Table Header
    printf("%-5s %-25s %-10s %-10s \n", "|ID|", "|Product Name|", "|Product Quantity|", "|Product Price|");
    printf("---------------------------------------------\n");
    printf("%-5d %-25s %-5d %-2f \n", ptr->product_id, ptr->name, ptr->quantity, ptr->price);
}

int add_product(void)
{
    get_prod_ID(&ITEM);
    get_prod_name(&ITEM);
    get_prod_quantity(&ITEM);
    get_prod_price(&ITEM);
    // TODO Write data into file
    FILE* file_ptr = open_file(WRITE_MODE);
    fwrite(&ITEM, sizeof(Product), 1, file_ptr);
    fclose(file_ptr);
    puts("Done");
    return EXIT_SUCCESS;
}

int view_all(void)
{
    FILE* file_ptr = open_file(READ_MODE);
    Product data;
    printf("%-5s %-15s %-10s %-10s \n", "|ID|", "|Product Name|", "|Product Quantity|", "|Product Price|");
    printf("----------------------------------------------------------\n");
    while (fread(&data, sizeof(Product), 1, file_ptr))
    {
        printf("%-5d %-15s %-10d %-2f \n", data.product_id, data.name, data.quantity, data.price);
    }
    fclose(file_ptr);
    return EXIT_SUCCESS;
}

FILE *open_file(const char* mode)
{
    FILE *file = fopen(FILENAME, mode);
    if (file == NULL)
    { // Handle error
        printf("File '%s' is not found. Creating a new one...\n", FILENAME);
        file = fopen(FILENAME, WRITE_MODE);
        fclose(file);
        file = fopen(FILENAME, mode);
        }
    return file;
}
void search_product(void){
    FILE *file_ptr = open_file(READ_MODE);
    if (search_func(file_ptr)){
        print_product(&ITEM);
            } 
    else{
        printf("Product Not found \n");
    }
    return;
}
bool search_func(FILE* file_ptr, ...)
{
    va_list args;
    va_start(args, file_ptr);
    bool update_mode = va_arg(args,int);
    int target_id;
    bool found = false;
    printf("Enter the Product ID \n");
    fgets(BUFFER, sizeof(BUFFER), stdin);
    sscanf(BUFFER, "%d", &target_id);
    while (fread(&ITEM, sizeof(Product), 1, file_ptr) == 1)
    {
        if (ITEM.product_id == target_id)
        {
            //puts("Found");
            found = true;
            if (update_mode)
                return found;
        }
    } 
    return found;
}

// BUG data update wrong
int update_product_func(Product *data_ptr, FILE *file_ptr)
{
    fseek(file_ptr, -sizeof(Product), SEEK_CUR);
    // print_product(&ITEM);
    if (fwrite(data_ptr, sizeof(Product), 1, file_ptr) != 1)
    {
        printf("Unsuccessful");
    }
    fclose(file_ptr);
    return EXIT_SUCCESS;
}

// TODO ASK THE USER WHAT  THEY WHAT TO UPDATE nAME, Q AND PRICE
void update_product()
{
    FILE *file_ptr = open_file(UPDATE_MODE);
    bool result = search_func(file_ptr, 1);
    if (!result)
    {
        printf("No Product with ID \n");
        return;
    }
    printf("Enter the number below to select the Product detail you want to update \n");
    printf("1. Product Name \n");
    printf("2. Product Quantity \n");
    printf("3. Product Price \n");
    fgets(BUFFER, sizeof(BUFFER), stdin);
    sscanf(BUFFER, "%d", &user_choice);
    switch (user_choice)
    {
    case 1:
        // Name
        get_prod_name(&ITEM);
        update_product_func(&ITEM, file_ptr);
         break;
    case 2:
        // Quantity
        get_prod_quantity(&ITEM);
        update_product_func(&ITEM,file_ptr);
        break;
        //printf break;
    case 3:
        // Price
        get_prod_price(&ITEM);
        update_product_func(&ITEM,file_ptr);
        break;
    default:
        break;
    }
}



/** void flush(void){
user_choice = 0;
BUFFER = "\0";
memset(ITEM)
fclose(file_ptr);
puts("FILE CLOSED");
} 
**/