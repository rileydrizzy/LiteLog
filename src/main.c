/**
 * @file main.c
 * @author Ladipo Ipadeola
 * @brief
 *
 *
 *
 * @version 0.1
 * @date 01-01-2026
 * * @copyright Copyright (c) 2026
 * */

#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "def.h"

#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

char FILENAME[] = "inventory.dat";

void main_menu_display(void)
{
    char user_input[3];
    unsigned short user_choice;
    printf(BLUE BOLD "==============================\n" RESET);
    printf(GREEN "     WELCOME TO LITELOG MENU \n" RESET);
    printf(BLUE BOLD "==============================\n" RESET);
    puts(YELLOW BOLD "Enter the below to select\n" RESET);
    printf("1. Add new product \n");
    printf("2. View all product \n");
    printf("3. Search for a product \n");
    printf("4. Update product details \n");
    printf("5. Delete a product from the Inventory \n");
    printf("6. Exit \n");
    printf(RED BOLD " ENTER OPTION \n" RESET);
        
    if (fgets(user_input, sizeof(user_input), stdin) != NULL){
        if (sscanf(user_input, "%hu", &user_choice) !=EOF){
            if (user_choice <= 0 || user_choice >= 7){}
        }
    }
    
    // TODO MAKE USE OF CASE TO SWITCH LOGIC
        // printf("%hu\n", user_choice);
        switch(user_choice){
            case 1:
                add_product(FILENAME);
                break;
            case 2:
                read_test(FILENAME);
                break;
            case 3:
                // TODO Search
                break;
            case 4:
                // TODO Update
                break;
            case 5:
                // TODO Delete
                break;
            case 6:
                // TODO Exit
                break;
        }
        
    
}

int main(void)
{
    main_menu_display();
    return EXIT_SUCCESS;
}
