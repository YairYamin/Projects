#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Functions.h"

int main(void) {

    char rows_str[50];
    char cols_str[50];
    int rows=0, cols=0;
    int Exit_FSM_flag = 1 ;
    int User_choice =0;

    // Get the number of rows

    do {
        printf("Insert number of rows (1-50): ");
        fgets(rows_str, sizeof(rows_str), stdin);

        // Remove trailing newline
        rows_str[strcspn(rows_str, "\n")] = '\0';

        if (isOnlyNumbers(rows_str) && sscanf(rows_str, "%d", &rows) == 1 && rows >= 1 && rows <= 50) {
            break; // Valid input
        }

        printf("Wrong number of rows, please try again.\n");
    } while (1);

    // Get the number of columns

    do {
        printf("Insert number of columns (1-50): ");
        fgets(cols_str, sizeof(cols_str), stdin);

        // Remove trailing newline
        cols_str[strcspn(cols_str, "\n")] = '\0';

        if (isOnlyNumbers(cols_str) && sscanf(cols_str, "%d", &cols) == 1 && cols >= 1 && cols <= 50) {
            break; // Valid input
        }

        printf("Wrong number of columns, please try again.\n");
    } while (1);

    // Declare and initialize the array

    int** matrix_A = initializeMatrix(rows, cols);

    //User Choice from the menu

    while(Exit_FSM_flag == 1)
    {
        User_choice = choice_from_menu();
        switch(User_choice)
        {
            case 0:
            {
                // Exit FSM
                Exit_FSM_flag = 0;
                printf("Exit\n");
            }
            break;
            case 1:
            {
                // Display the matrix
                print_matrix(matrix_A, rows, cols);
            }
            break;
            case 2:
            {
                // Insert values to the matrix
                set_matrix_values(matrix_A, rows, cols);
            }
            break;
            case 3:
            {
                // Transpose matrix
                Transform_matrix(&matrix_A, &rows, &cols);
            }
            break;
            case 4:
            {
                // Sort the matrix by rows sum
                sort_by_rows_sum(matrix_A, rows, cols);
            }
            break;
            case 5:
            {
                // Sort the whole matrix
                sort_whole_matrix(matrix_A, rows, cols);
            }
            break;
            case 6:
            {
                // Print matrix value
                print_matrix_6(matrix_A, rows, cols);
            }
            break;
            case 7:
            {
                // i-th power of matrix
                power_i_of_matrix(&matrix_A, &rows, &cols);
            }
            break;
            case 8:
            {   // Find sub matrix
                return_sub_matrix(&matrix_A, &rows, &cols);
            }
            break;
            case 9:
            {
                // Multiply with another matrix
                multiply_matrix(&matrix_A, &rows, &cols);
            }
            break;
            default:
                printf("Invalid choice. Try again.\n");

        }
    }
    return 0;
}



