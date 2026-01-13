/**
* @file util.c
     * @author Ladipo Ipadeola
     * @brief This file contains the utility functions for the inventory management system.
     * @version 0.1
     * @date 01-01-2026
     * @copyright Copyright (c) 2026
     */

#include "util.h"
#include "def.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>


extern const char *FILENAME;
extern const char *TEMP_FILE;
extern char BUFFER[30];
extern Product ITEM;
extern int user_choice;

void get_clean_input(void)
{
    if (fgets(BUFFER, sizeof(BUFFER), stdin))
    {
        // Checked if the input is larger than the Buffer
        char *p = strchr(BUFFER, '\n');
        if (p)
        {
            *p = '\0';
        }
        else
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
        BUFFER[strcspn(BUFFER, "\n")] = 0;
    }
}

void get_prod_ID(Product *data_ptr)
{
    puts("Enter the Product ID:");
    get_clean_input();
    if (sscanf(BUFFER, "%d", &data_ptr->product_id) != EOF)
    {
        printf("Product ID: %d \n", data_ptr->product_id);
    }
}


void get_prod_name(Product *data_ptr)
{
    puts("Enter the Product Name:");
    get_clean_input();
    snprintf(data_ptr->name, sizeof(data_ptr->name), "%s", BUFFER);
    printf("Product Name: %s \n", data_ptr->name);
}

void get_prod_quantity(Product *data_ptr)
{
    puts("Enter the Product Quantity:");
    get_clean_input();
    if (sscanf(BUFFER, "%d", &data_ptr->quantity) != EOF)
    {
        printf("Product ID: %d \n", data_ptr->quantity);
    }
}

void get_prod_price(Product *data_ptr)
{
    puts("Enter the Product Price:");
    get_clean_input();
    if (sscanf(BUFFER, "%f", &data_ptr->price) != EOF)
    {
        printf("Product ID: %.2f \n", data_ptr->price);
    }
}

void print_table_header(void)
{
    printf("| %-*s | %-*s | %-*s | %-*s |\n",
           W_ID, "ID",
           W_NAME, "Name",
           W_QTY, "Quantity",
           W_PRICE, "Price");

    printf("|-%-*s-|-%-*s-|-%-*s-|-%-*s-|\n",
           W_ID, "------",
           W_NAME, "--------------------",
           W_QTY, "----------",
           W_PRICE, "----------");
    return;
}

void print_product_row(Product *ptr)
{
    printf("| %-*d | %-*.*s | %-*d | %-*.2f |\n",
           W_ID, ptr->product_id,
           W_NAME, W_NAME, ptr->name, // Width and Precision both set to W_NAME
           W_QTY, ptr->quantity,
           W_PRICE, ptr->price);
    return;
}

void print_table_divider(void)
{
    printf("|-%-*s-|-%-*s-|-%-*s-|-%-*s-|\n",
           W_ID, "------",
           W_NAME, "--------------------",
           W_QTY, "----------",
           W_PRICE, "----------");
}

void print_table_footer(Total *ptr)
{
    print_table_divider();
    printf("| %-*s | %*s | %-*d | %-*.2f |\n",
           W_ID, "",                  // Blank ID
           W_NAME, "TOTALS:",         // Right-aligned Label
           W_QTY, ptr->total_no_prod, // Total Quantity
           W_PRICE, ptr->total_val);  // Total Value
    print_table_divider();
}

int view_all(void)
{
    FILE *file_ptr = open_file(FILENAME, READ_MODE);
    Total TOL = {0};
    print_table_header();
    while (fread(&ITEM, sizeof(Product), 1, file_ptr) >= 1)
    {
        print_product_row(&ITEM);
        TOL.total_no_prod += 1;
        TOL.total_val += ITEM.price;
    }
    print_table_footer(&TOL);
    fclose(file_ptr);
    clean_up();
    return EXIT_SUCCESS;
}

int add_product(void)
{
    get_prod_ID(&ITEM);
    get_prod_name(&ITEM);
    get_prod_quantity(&ITEM);
    get_prod_price(&ITEM);
    FILE *file_ptr = open_file(FILENAME, WRITE_MODE);
    if (fwrite(&ITEM, sizeof(Product), 1, file_ptr))
        printf("Data Saved Successfully");
    fclose(file_ptr);
    clean_up();
    return EXIT_SUCCESS;
}

FILE *open_file(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    { // Handle error
        printf("File '%s' is not found. Creating a new one...\n", filename);
        file = fopen(filename, WRITE_MODE);
        fclose(file);
        file = fopen(filename, mode);
    }
    return file;
}

void search_product(void)
{
    FILE *file_ptr = open_file(FILENAME, READ_MODE);
    if (search_func(file_ptr))
    {
        print_table_header();
        print_product_row(&ITEM);
    }
    else
    {
        printf("Product with the ID not found \n");
    }
    return;
}

bool search_func(FILE *file_ptr, ...)
{
    va_list args;
    va_start(args, file_ptr);
    bool update_mode = va_arg(args, int);
    bool found = false;
    int target_id;
    printf("Enter the Product ID \n");
    get_clean_input();
    sscanf(BUFFER, "%d", &target_id);
    while (fread(&ITEM, sizeof(Product), 1, file_ptr) == 1)
    {
        if (ITEM.product_id == target_id)
        {
            // puts("Found");
            found = true;
            break;
        }
    }
    return found;
}

int update_product_func(Product *data_ptr, FILE *file_ptr)
{
    fseek(file_ptr, -sizeof(Product), SEEK_CUR);
    if (fwrite(data_ptr, sizeof(Product), 1, file_ptr) != 1)
    {
        printf("Unsuccessful");
    }
    fclose(file_ptr);
    return EXIT_SUCCESS;
}

void update_product(void)
{
    FILE *file_ptr = open_file(FILENAME, UPDATE_MODE);
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
    get_clean_input();
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
        update_product_func(&ITEM, file_ptr);
        break;
        // printf break;
    case 3:
        // Price
        get_prod_price(&ITEM);
        update_product_func(&ITEM, file_ptr);
        break;
    default:
        break;
    }
}

void delete_product(void)
{
    FILE *file_ptr = open_file(FILENAME, READ_MODE);
    bool result = search_func(file_ptr, 0);
    fclose(file_ptr);
    if (!result)
    {
        printf("No Product with ID \n");
        return;
    }
    Product temp_data;
    FILE *temp_file = open_file(TEMP_FILE, WRITE_MODE);
    file_ptr = open_file(FILENAME, READ_MODE);
    while (fread(&temp_data, sizeof(Product), 1, file_ptr) == 1)
    {
        if (ITEM.product_id != temp_data.product_id)
        {
            fwrite(&temp_data, sizeof(Product), 1, temp_file);
        }
    }
    fclose(temp_file);
    fclose(file_ptr);
    remove(FILENAME);
    rename(TEMP_FILE, FILENAME);
    return;
}

void clean_up(void)
{
    user_choice = 0;
    // BUFFER[0] = '\0';
    memset(BUFFER, 0, sizeof(BUFFER));
    memset(&ITEM, 0, sizeof(Product));
    return;
}


int check_prod_id_avail(int id){
    FILE *file_ptr = open_file(FILENAME, READ_MODE);
    bool result = search_func(file_ptr, 0);
    fclose(file_ptr);
    if (result){
        return 1;
    }
    return 0;
}