//A program to find if an array of integers contains a duplicate number
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int *array; // Pointer to the array
    int n;      // Number of elements
    int hasDuplicates = 0; // Flag to indicate if duplicates are found

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

    // Sort the array
    qsort(array, n, sizeof(int), compare);

    // Check for duplicates in the sorted array
    for (int i = 1; i < n; i++) {
        if (array[i] == array[i - 1]) {
            hasDuplicates = 1;
            break;
        }
    }

    // Print the result
    if (hasDuplicates) {
        printf("The array contains duplicate numbers.\n");
    } else {
        printf("The array does not contain any duplicate numbers.\n");
    }

    // Free the allocated memory
    free(array);

    return 0;
}
