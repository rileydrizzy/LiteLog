/**
 * @file main.c
 * @author Ladipo Ipadeola
 * @brief
 *
 *
 *
 * @version 0.1
 * @date 01-01-2026
 * @copyright Copyright (c) 2026
 * */

#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "def.h"
#include <stdbool.h>

char FILENAME[] = "inventory.dat";
char BUFFER[60];
Product ITEM;
unsigned short user_choice;


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
    printf("5. Delete a product from the Inventory \n");
    printf("6. Exit \n");
    printf(RED BOLD " ENTER OPTION \n" RESET);

    if (fgets(user_input, sizeof(user_input), stdin) != NULL)
    {
        if (sscanf(user_input, "%hu", &user_choice) != EOF)
        {
            if (user_choice <= 0 || user_choice >= 7)
            {
            }
        }
    }
    // printf("%hu\n", user_choice);
    switch (user_choice)
    {
    case 1:
        add_product(FILENAME);
        break;
    case 2:
        view_all(FILENAME);
        break;
    case 3:
        // TODO Search
        search_item(FILENAME);
        break;
    case 4:
        // TODO Update
        break;
    case 5:
        // TODO Delete
        break;
    case 6:
        // TODO Exit
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
