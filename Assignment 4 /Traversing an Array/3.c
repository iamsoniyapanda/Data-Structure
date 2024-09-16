//A program to print the position of the smallest number of n numbers using array
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;  // Pointer to the array
    int n;       // Number of elements
    int minIndex; // Index of the smallest number
    int minValue; // Value of the smallest number

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for n integers
    array = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read n elements into the array
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Initialize minValue to the first element and minIndex to 0
    minValue = array[0];
    minIndex = 0;

    // Find the smallest number and its index
    for (int i = 1; i < n; i++) {
        if (array[i] < minValue) {
            minValue = array[i];
            minIndex = i;
        }
    }

    // Print the position (index) of the smallest number
    printf("The smallest number is %d and is located at position %d (0-based index).\n", minValue, minIndex);

    // Free the allocated memory
    free(array);

    return 0;
}
