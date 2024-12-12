
# Matrix Mathematics Project

This project provides a command-line application for performing various matrix operations. It is implemented in C and is structured to handle operations such as matrix transposition, sorting, multiplication, submatrix extraction, and more.

## Features

1. **Matrix Initialization**:
   - Dynamically allocate a 2D array for matrix storage.
   - Initialize the matrix with zero values.

2. **Matrix Display**:
   - Print the matrix in a tabular format.

3. **Matrix Value Insertion**:
   - Input values for a user-defined matrix of size (rows x columns).

4. **Matrix Transposition**:
   - Transpose the matrix by swapping rows and columns.

5. **Sorting**:
   - Sort rows of the matrix based on their sums.
   - Sort all elements in the matrix in ascending order.

6. **Matrix Properties**:
   - Compute the weighted sum of all matrix elements.

7. **Matrix Power**:
   - Raise a square matrix to a user-defined positive integer power.

8. **Submatrix Extraction**:
   - Extract a submatrix from a larger matrix based on user-defined dimensions and positions.

9. **Matrix Multiplication**:
   - Multiply two matrices if their dimensions allow.
   - Multiply the matrix with another user-defined matrix.

## Files in the Project

1. **`main.c`**:
   - Contains the main logic for the program.
   - Handles user input and menu-driven interaction for performing operations on matrices.

2. **`Functions.h`**:
   - Header file that declares all the functions used in the project.

3. **`Functions.c`**:
   - Implementation of the functions declared in `Functions.h`.
   - Includes operations for initialization, matrix manipulation, sorting, and mathematical computations.

## How to Use

1. Compile the program:
   ```bash
   gcc main.c Functions.c -o matrix_math
   ```

2. Run the executable:
   ```bash
   ./matrix_math
   ```

3. Follow the menu to perform operations:
   - Enter the number of rows and columns (1-50) for the matrix.
   - Choose an operation from the menu:
     - Display the matrix.
     - Insert values.
     - Transpose the matrix.
     - Sort by row sums or all elements.
     - Compute the matrix power.
     - Extract a submatrix.
     - Multiply matrices.

4. Exit the program by selecting the `Exit` option from the menu.

## Notes

- The matrix size is restricted to a maximum of 50x50.
- Input validation ensures appropriate values for matrix dimensions and operations.
- Memory management is handled dynamically, ensuring efficient use of resources.

## Requirements

- GCC or any other C compiler.
- A terminal or command-line environment.
