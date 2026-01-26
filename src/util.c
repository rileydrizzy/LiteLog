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
#include <string.h>

extern const char *FILENAME;
extern const char *TEMP_FILE;

void get_clean_input(char *out_buffer, int size)
{
    if (fgets(out_buffer, size, stdin))
    {
        // Checked if the input is larger than the Buffer
        char *p = strchr(out_buffer, '\n');
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
        out_buffer[strcspn(out_buffer, "\n")] = 0;
    }
}

void get_prod_ID(char *out_buffer, Product *data_ptr)
{
    puts("Enter the Product ID:");
    get_clean_input(out_buffer, 5);
    if (sscanf(out_buffer, "%d", &data_ptr->product_id) != EOF)
    {
        printf("Product ID: %d \n", data_ptr->product_id);
    }
}

void get_prod_name(char *out_buffer, Product *data_ptr)
{
    puts("Enter the Product Name:");
    get_clean_input(out_buffer, BUFFER_SIZE);
    snprintf(data_ptr->name, sizeof(data_ptr->name), "%s", out_buffer);
    printf("Product Name: %s \n", data_ptr->name);
}

void get_prod_quantity(char *out_buffer, Product *data_ptr)
{
    puts("Enter the Product Quantity:");
    get_clean_input(out_buffer, BUFFER_SIZE);
    if (sscanf(out_buffer, "%d", &data_ptr->quantity) != EOF)
    {
        printf("Product Quantity: %d \n", data_ptr->quantity);
    }
}

void get_prod_price(char *out_buffer, Product *data_ptr)
{
    puts("Enter the Product Price:");
    get_clean_input(out_buffer, BUFFER_SIZE);
    if (sscanf(out_buffer, "%f", &data_ptr->price) != EOF)
    {
        printf("Product Price: %.2f \n", data_ptr->price);
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

int view_all(Product *data_ptr)
{
    FILE *file_ptr = open_file(FILENAME, READ_MODE);
    Total TOL = {0}; // TODO Change variable name
    print_table_header();
    while (fread(data_ptr, sizeof(Product), 1, file_ptr) >= 1)
    {
        print_product_row(data_ptr);
        TOL.total_no_prod += 1;
        TOL.total_val += data_ptr->price;
    }
    print_table_footer(&TOL);
    fclose(file_ptr);
    clean_up(NULL, data_ptr);
    return EXIT_SUCCESS;
}

int add_product(char *out_buffer, Product *data_ptr)
{
    do
    {
        get_prod_ID(out_buffer, data_ptr);
        bool prod_dulp_check = check_prod_id_avail(data_ptr);
        if (prod_dulp_check)
        {
            printf("The Product ID %d already exits \n", data_ptr->product_id);
            continue;
        }

        get_prod_name(out_buffer, data_ptr);
        get_prod_quantity(out_buffer, data_ptr);
        get_prod_price(out_buffer, data_ptr);
        FILE *file_ptr = open_file(FILENAME, WRITE_MODE);
        if (fwrite(data_ptr, sizeof(Product), 1, file_ptr))
            printf("Product Data Saved Successfully \n");
        fclose(file_ptr);
        clean_up(out_buffer, data_ptr);
        return EXIT_SUCCESS;
    } while (true);
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

void search_product(char *out_buffer, Product *data_ptr)
{
    FILE *file_ptr = open_file(FILENAME, READ_MODE);
    if (search_func(file_ptr, out_buffer, data_ptr))
    {
        print_table_header();
        print_product_row(data_ptr);
    }
    else
    {
        printf("Product with the ID not found \n");
    }
    fclose(file_ptr);
    clean_up(out_buffer, data_ptr);
    return;
}

bool search_func(FILE *file_ptr, char *out_buffer, Product *data_ptr)
{
    bool found = false;
    int target_id;
    printf("Enter the Product ID \n");
    get_clean_input(out_buffer, sizeof(Product));
    sscanf(out_buffer, "%d", &target_id);
    while (fread(data_ptr, sizeof(Product), 1, file_ptr) == 1)
    {
        if (data_ptr->product_id == target_id)
        {
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

void update_product(char *out_buffer, Product *data_ptr)
{
    int user_choice;
    FILE *file_ptr = open_file(FILENAME, UPDATE_MODE);
    bool result = search_func(file_ptr, out_buffer, data_ptr);
    if (!result)
    {
        printf("No Product with ID \n");
        fclose(file_ptr);
        return;
    }
    printf("Enter the number below to select the Product detail you want to update \n");
    printf("1. Product Name \n");
    printf("2. Product Quantity \n");
    printf("3. Product Price \n");
    get_clean_input(out_buffer, sizeof(Product));
    sscanf(out_buffer, "%d", &user_choice);
    switch (user_choice)
    {
    case 1:
        // Name
        get_prod_name(out_buffer, data_ptr);
        update_product_func(data_ptr, file_ptr);
        break;
    case 2:
        // Quantity
        get_prod_quantity(out_buffer, data_ptr);
        update_product_func(data_ptr, file_ptr);
        break;
    case 3:
        // Price
        get_prod_price(out_buffer, data_ptr);
        update_product_func(data_ptr, file_ptr);
        break;
    default:
        break;
    }
    clean_up(out_buffer, data_ptr);
}

void delete_product(char *out_buffer, Product *data_ptr)
{
    FILE *file_ptr = open_file(FILENAME, READ_MODE);
    bool result = search_func(file_ptr, out_buffer, data_ptr);
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
        if (data_ptr->product_id != temp_data.product_id)
        {
            fwrite(&temp_data, sizeof(Product), 1, temp_file);
        }
    }
    fclose(temp_file);
    fclose(file_ptr);
    remove(FILENAME);
    rename(TEMP_FILE, FILENAME);
    clean_up(out_buffer, data_ptr);
    return;
}

void clean_up(char *input_buffer, Product *data_ptr)
{
    // user_choice = 0;
    if (input_buffer != NULL)
        memset(input_buffer, 0, sizeof(char) * BUFFER_SIZE);
    if (data_ptr != NULL)
        memset(data_ptr, 0, sizeof(Product));
    return;
}

bool check_prod_id_avail(Product *data_ptr)
{
    FILE *file_ptr = open_file(FILENAME, READ_MODE);
    Product temp_data;
    bool result = false;
    while (fread(&temp_data, sizeof(Product), 1, file_ptr) == 1)
    {
        if (data_ptr->product_id == temp_data.product_id)
        {
            result = true;
            break;
        }
    }
    fclose(file_ptr);
    return result;
}
