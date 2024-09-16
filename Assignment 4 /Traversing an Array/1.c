//A program to read and display n numbers using an array

#include <stdio.h>
#include <stdlib.h>
int main() {
    int *array; // Pointer to the array
    int n;      // Number of elements

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

    // Display the elements of the array
    printf("\nYou entered:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i + 1, array[i]);
    }

    // Free the allocated memory
    free(array);

    return 0;
}
