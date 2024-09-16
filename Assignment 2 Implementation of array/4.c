// A program of 2d metrics from the console verifies if multiplication is possible or not then multiplies the metrics and prints the 3D metrics
#include <stdio.h>

#define MAX_SIZE 100

// Function prototypes
void readMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[][MAX_SIZE], int rows1, int cols1,
                      int mat2[][MAX_SIZE], int rows2, int cols2,
                      int result[][MAX_SIZE]);

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions for the first matrix
    printf("Enter number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    // Input dimensions for the second matrix
    printf("Enter number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. Number of columns in the first matrix must equal the number of rows in the second matrix.\n");
        return 1;
    }

    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    // Input matrices
    printf("Enter elements for the first matrix:\n");
    readMatrix(mat1, rows1, cols1);

    printf("Enter elements for the second matrix:\n");
    readMatrix(mat2, rows2, cols2);

    // Multiply matrices
    multiplyMatrices(mat1, rows1, cols1, mat2, rows2, cols2, result);

    // Print the resulting matrix
    printf("Resulting matrix after multiplication:\n");
    printMatrix(result, rows1, cols2);

    return 0;
}

// Function to read matrix elements from user input
void readMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix elements
void printMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[][MAX_SIZE], int rows1, int cols1,
                      int mat2[][MAX_SIZE], int rows2, int cols2,
                      int result[][MAX_SIZE]) {
    // Initialize result matrix with zeros
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    // Multiply matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
