//Print elements of a m X n array
#include <stdio.h>
#define MAX_SIZE 100 
void print2DArray(int arr[MAX_SIZE][MAX_SIZE], int m, int n);

int main() {
    int arr[MAX_SIZE][MAX_SIZE]; // 2D array
    int m, n;

    // Read the dimensions of the 2D array
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    // Validate the dimensions
    if (m <= 0 || m > MAX_SIZE || n <= 0 || n > MAX_SIZE) {
        printf("Error: Dimensions must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Read the elements of the 2D array
    printf("Enter the elements of the %d x %d array:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Print the elements of the 2D array
    printf("The elements of the %d x %d array are:\n", m, n);
    print2DArray(arr, m, n);

    return 0;
}

// Function to print the elements of a 2D array
void print2DArray(int arr[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
