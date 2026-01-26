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
#include <string.h>
#include "util.h"
#include "def.h"

// Global Variables
const char *FILENAME = "inventory.dat";
const char *TEMP_FILE = "temp.dat";

/**
 * @brief This function displays the main menu of the program.
 * @param void
 * @return void
 */
void main_menu_display(void)
{
    char BUFFER[BUFFER_SIZE];
    Product ITEM;
    char user_input[3];
    int user_choice = 0;
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
        char *p = strchr(user_input, '\n');
        if (p)
            *p = '\0';
        else
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        if (sscanf(user_input, "%d", &user_choice) != EOF)
        {
            if (user_choice <= 0 || user_choice >= MENU_EXIT_OPTION)
            {
                printf("The number you input is not part of the option \n");
                printf("Try again \n");
            }
        }
    }
    switch (user_choice)
    {
    case 1:
        add_product(BUFFER, &ITEM);
        break;
    case 2:
        view_all(&ITEM);
        break;
    case 3:
        search_product(BUFFER, &ITEM);
        break;
    case 4:
        update_product(BUFFER, &ITEM);
        break;
    case 5:
        delete_product(BUFFER, &ITEM);
        break;
    case 6:
        keep_running = false;
        break;
    }
}

int main(void)
{
    bool keep_running = true;
    while(keep_running){main_menu_display()}
    return EXIT_SUCCESS;
}
