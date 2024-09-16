//A program to transpose a m X n matrix
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

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int transposed[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int m, n;

    // Input dimensions of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print original matrix
    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, m, n);

    // Transpose the matrix
    transposeMatrix(matrix, m, n, transposed);

    // Print transposed matrix
    printf("\nTransposed Matrix:\n");
    printMatrix(transposed, n, m);

    return 0;
}
