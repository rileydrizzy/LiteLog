/**
 * @file main.c
 * @author Ladipo Ipadeola
 * @brief This is the main file for the inventory management system. This file contains the main function and the main menu display function.
 * This program is a simple inventory management system that allows users to add, view, search, update and delete products.
 * The program uses a binary file to store the products.
 * The program is written in C and uses the standard library functions.
 * @version 0.1
 * @date 01-01-2026
 * @copyright Copyright (c) 2026
 * */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"
#include "def.h"

const char *FILENAME = "inventory.dat";
const char *TEMP_FILE = "temp.dat";
char BUFFER[30];
Product ITEM;
int user_choice;


/**
* @brief This function displays the main menu of the program.
* @param void
* @return void
* @note This function is called in the main function.
*/
void main_menu_display(void)
{
    char user_input[3];
    printf(BLUE BOLD "==============================\n" RESET);
    printf(GREEN "     WELCOME TO LITELOG MENU \n" RESET);
    printf(BLUE BOLD "==============================\n" RESET);
    printf(YELLOW BOLD "Enter the number below to select an option\n" RESET);
    printf("1. Add new product \n");
    printf("2. View all product \n");
    printf("3. Search for a product \n");
    printf("4. Update product details \n");
    printf("5. Delete a product \n");
    printf("6. Exit \n");
    printf(RED BOLD " ENTER OPTION \n" RESET);

    if (fgets(user_input, sizeof(user_input), stdin) != NULL)
    {
        if (sscanf(user_input, "%d", &user_choice) != EOF)
        {
            if (user_choice <= 0 || user_choice >= 7)
            {
                printf("The number you input is not part of the option \n. Try again \n");
            }
        }
    }
    switch (user_choice)
    {
    case 1:
        add_product();
        break;
    case 2:
        view_all();
        break;
    case 3:
        search_product();
        break;
    case 4:
        update_product();
        break;
    case 5:
        delete_product();
        break;
    case 6:
        exit(EXIT_SUCCESS);
        break;
    }
}

int main(void)
{
    do
    {
        main_menu_display();
    } while (true);
    return EXIT_SUCCESS;
}
