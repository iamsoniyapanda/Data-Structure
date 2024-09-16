//A  program to calculate two m X n matrices
#include <stdio.h>
#define MAX_SIZE 100  
// Function to input matrix elements
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int m, n;

    // Input dimensions of the matrices
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    // Input first matrix
    printf("Input for first matrix:\n");
    inputMatrix(matrix1, m, n);

    // Input second matrix
    printf("Input for second matrix:\n");
    inputMatrix(matrix2, m, n);

    // Calculate and display matrix addition
    addMatrices(matrix1, matrix2, result, m, n);
    printf("\nMatrix Addition Result:\n");
    printMatrix(result, m, n);

    // Calculate and display matrix subtraction
    subtractMatrices(matrix1, matrix2, result, m, n);
    printf("\nMatrix Subtraction Result:\n");
    printMatrix(result, m, n);

    return 0;
}
