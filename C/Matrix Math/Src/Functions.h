//
// Created by yairy on 09/12/2024.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//Functions declaration
int** initializeMatrix(int rows, int cols);
int isOnlyNumbers(const char *str);
int choice_from_menu(void);
void print_matrix( int** matrix,  int rows,  int cols);
void set_matrix_values( int** matrix,  int rows,  int cols);
void Transform_matrix( int*** matrix,  int* rows,  int* cols);
void freeArray( int** array,  int rows) ;
void sort_by_rows_sum( int** matrix,  int rows,  int cols);
int sum_of_row( int* array ,  int num_columns);
void sort_whole_matrix( int** matrix,  int rows,  int cols);
void print_matrix_6( int** matrix,  int rows,  int cols);
void multiplyMatrices(int** mat1, int rows1, int cols1, int** mat2, int rows2, int cols2, int** result);
void power_i_of_marix( int*** matrix,  int *rows,  int *cols);
void return_sub_matrix( int*** matrix,  int* rows,  int* cols);
void multiply_matrix( int*** matrix,  int* rows,  int* cols);
#endif //FUNCTIONS_H
