
//A program to input two m X n ,matrices and then calculate the sum of their corresponding elements and store it in a third m X n
#include <stdio.h>
#define MAX_SIZE 100

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], sumMatrix[MAX_SIZE][MAX_SIZE];
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

    // Calculate the sum of the matrices
    addMatrices(matrix1, matrix2, sumMatrix, m, n);

    // Print the resulting matrix
    printf("\nSum of the two matrices:\n");
    printMatrix(sumMatrix, m, n);

    return 0;
}

