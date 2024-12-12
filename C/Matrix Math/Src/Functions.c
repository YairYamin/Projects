//Includes
#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Function that allocate 2-D array in memory
int** initializeMatrix(int rows, int cols) {
    // Allocate memory for the matrix
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        return NULL; // Handle memory allocation failure
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            // Free already allocated rows in case of failure
            for (int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            return NULL;
        }
    }

    // Initialize all elements to 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

//Function that string and check if it is consisted from numbers only
int isOnlyNumbers(const char *str) {

    if (str == NULL || *str == '\0') {
        return 0; // Empty or NULL string is not valid
    }
    while(*str && isspace((unsigned char) *str)) {
        str++;
    }
    while (*str) {
        if (!isdigit((unsigned char)*str)) {
            return 0; // Return false if any non-digit character is found
        }
        str++;
    }

    return 1; // All characters are digits
}

//Function that print the menu to console and get the user choice
int choice_from_menu(void) {
    int choice ;
    printf("1. Display the matrix.\n");
    printf("2. Insert values to the matrix.\n");
    printf("3. Transpose matrix.\n");
    printf("4. Sort the matrix by rows sum.\n");
    printf("5. Sort the whole matrix.\n");
    printf("6. Print matrix value.\n");
    printf("7. i-th power of matrix.\n");
    printf("8. Find sub matrix.\n");
    printf("9. Multiply with another matrix.\n");
    printf("0. Exit.\n");
    printf("Please enter your choice: ");
    fflush(stdout);
    scanf("%d", &choice);

    while (choice < 0 || choice > 9) {
        printf("Wrong input, try again.\n");
        printf("1.Display the matrix.\n");
        printf("2.Insert values to the matrix.\n");
        printf("3.Transpose matrix.\n");
        printf("4.Sort the matrix by rows sum.\n");
        printf("5.Sort the whole matrix.\n");
        printf("6.Print matrix value.\n");
        printf("7.i-th power of matrix.\n");
        printf("8.Find sub matrix.\n");
        printf("9.Multiply with another matrix.\n");
        printf("0.Exit.\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

    }
    return choice ;

}

//Function that print the matrix
void print_matrix( int** matrix,  int rows,  int cols)
{   printf("\n");
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == cols - 1)
            {
                printf("%d", matrix[i][j]);//Without gap in the end of the row
            }
            else
            {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

//Function that set values to matrix
void set_matrix_values( int** matrix, int  rows,  int cols)
{
    printf("Enter values for the matrix (%d x %d):\n",rows,cols);
for (int i = 0; i <rows;i++)
{
    for (int j = 0; j < cols; j++)
    {
    scanf("%d", &matrix[i][j]);
    }
}

}

//Function that free memory allocation
void freeArray( int** array,  int rows)
{
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

//Function that calculate the transform of matrix
void Transform_matrix( int*** matrix,  int* rows,  int* cols)
{
     int **original = *matrix;
     int new_rows = *cols;
     int new_cols = *rows;
    // Declare and initialize the new array
    int** new_matrix = initializeMatrix(new_rows, new_cols);
    for (int i=0;i<new_rows;i++)
    {
        for (int j=0;j<new_cols;j++)
        {
            new_matrix[i][j] = original[j][i];
        }
    }
    freeArray(original,*rows);
    *matrix = new_matrix;
    *rows = new_rows;
    *cols = new_cols;
}

//Function that calculate the sum of matrix row
int sum_of_row( int* array ,  int num_columns)
{
    int sum = 0;
    for (int i = 0; i < num_columns; i++) {
        sum += array[i];
    }
    return sum;
}

//Function that organize the matrix by the sum of the rows
void sort_by_rows_sum( int** matrix,  int rows,  int cols)
{
    int matrix_are_sorted = 0;
     int* temp;
    while(matrix_are_sorted == 0)
    {
        matrix_are_sorted = 1 ;
        for (int i = 0; i < rows-1; i++)
        {   if (sum_of_row(matrix[i],cols) > sum_of_row(matrix[i+1],cols))
            {
            matrix_are_sorted = 0;
            temp = matrix[i];
            matrix[i] = matrix[i+1];
            matrix[i+1] = temp;
            }
        }
    }

}

//Function that sort the matrix by descending order
void sort_whole_matrix(int** matrix, int rows, int cols) {
    int size = rows * cols;
    int* flat_array = (int*)malloc(size * sizeof(int));
    if (flat_array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Flatten the 2D matrix into a 1D array
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            flat_array[index++] = matrix[i][j];
        }
    }

    // Sort the 1D array
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (flat_array[j] > flat_array[j + 1]) {
                int temp = flat_array[j];
                flat_array[j] = flat_array[j + 1];
                flat_array[j + 1] = temp;
            }
        }
    }

    // Reconstruct the 2D matrix from the sorted 1D array
    index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = flat_array[index++];
        }
    }

    free(flat_array);
}

//Function that Print the sum of row * column* value of all the matrix elements
void print_matrix_6( int** matrix,  int rows,  int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += (matrix[i][j] * (i+1) * (j+1) );
        }
    }
    printf("Matrix value: %d\n", sum);
}

// Function to multiply two matrices with different dimensions
void multiplyMatrices(int** mat1, int rows1, int cols1, int** mat2, int rows2, int cols2, int** result) {
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible: Columns of mat1 must equal rows of mat2.\n");
        return;
    }

    // Initialize the result matrix to 0
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to calculate the power of a matrix
void power_i_of_matrix(int*** matrix, int* rows, int* cols) {
    if (*rows != *cols) {
        printf("Matrix must be square for this operation.\n");
        return;
    }

    int size = *rows;
    int power;
    printf("Enter power: ");
    scanf("%d", &power);

    // Validate power input
    while (power <= 0) {
        printf("The power must be an integer greater than 0.\n");
        printf("Enter power: ");
        scanf("%d", &power);
    }

    // Initialize result matrix as a copy of the input matrix
    int** result_matrix = initializeMatrix(size, size);
    int** temp_matrix = initializeMatrix(size, size);

    // Copy the original matrix into result_matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result_matrix[i][j] = (*matrix)[i][j];
        }
    }

    // Compute matrix power
    for (int p = 1; p < power; p++) {
        // Multiply result matrix by the original matrix
        multiplyMatrices(result_matrix, size, size,*matrix, size, size, temp_matrix);
        // Copy temp_matrix back to result_matrix
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result_matrix[i][j] = temp_matrix[i][j];
            }
        }
    }

    // Free temporary matrix
    freeArray(temp_matrix, size);

    // Update the original matrix pointer
    freeArray(*matrix, size);
    *matrix = result_matrix;
}

// Function that return sub-matrix from the original matrix
void return_sub_matrix( int*** matrix,  int* rows,  int* cols)
{
    int sub_rows = 0, sub_cols =0,base_row = 0,base_cols =0;
    int** original = *matrix;
    printf("Enter submatrix rows: ");
    scanf("%d", &sub_rows);
    printf("Enter base row: ");
    scanf("%d", &base_row);
    printf("Enter submatrix columns: ");
    scanf("%d", &sub_cols);
    printf("Enter base col: ");
    scanf("%d", &base_cols);
    while((sub_rows + base_row)>*rows || (sub_cols + base_cols)>*cols)
    {
        printf("Submatrix size exceeds original matrix dimensions.\n");
        printf("Enter submatrix rows: ");
        scanf("%d", &sub_rows);
        printf("Enter base row: ");
        scanf("%d", &base_row);
        printf("Enter submatrix columns: ");
        scanf("%d", &sub_cols);
        printf("Enter base col: ");
        scanf("%d", &base_cols);
    }
    int** temp_metrix = initializeMatrix(sub_rows, sub_cols);
    for (int i = 0; i < sub_rows; i++)
    {

        for (int j = 0; j < sub_cols; j++)
        {
            temp_metrix[i][j] = original[base_row + i][base_cols + j];
        }
    }
    *matrix = temp_metrix;
    *rows = sub_rows;
    *cols = sub_cols;
}

//Function that calculate matrix multiplication when it is giving that Nu. of rows in MAT_B = Nu. of cols on MAT_A
void multiply_matrix( int*** matrix,  int* rows,  int* cols)
{    int** original = *matrix;
     int matrix_B_rows = *cols,matrix_B_cols=0,sum=0;

    // Get second matrix number of columns from the user
    do {
        printf("Enter columns for the second matrix (must be greater than 0): ");
        scanf("%d", &matrix_B_cols);
        if (matrix_B_cols <= 0) {
            printf("Wrong value. The number of columns must be greater than 0.\n");
        }
    } while (matrix_B_cols <= 0);

    int** matrix_B = initializeMatrix(matrix_B_rows, matrix_B_cols);

    // Set values to matrix_B
    set_matrix_values(matrix_B, matrix_B_rows, matrix_B_cols);

    // Calculate the Multiplication

    int** temp_metrix = initializeMatrix(*rows,matrix_B_cols);
    multiplyMatrices(*matrix,*rows,*cols,matrix_B,matrix_B_rows,matrix_B_cols,temp_metrix);
    freeArray(original,*rows);
    freeArray(matrix_B,matrix_B_rows);
    *matrix = temp_metrix;
    *cols = matrix_B_cols;
}

