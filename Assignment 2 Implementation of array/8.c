// A program to allocate memory using mlloc() & then reallocate to prevoiusly allocated memory using realloc() display the elements which have been taken after reallocation
#include <stdio.h>
#include <stdlib.h>  // For malloc(), realloc(), and free()

int main() {
    int *array;
    int initialSize, newSize;

    // Allocate initial memory
    printf("Enter the number of initial elements: ");
    scanf("%d", &initialSize);

    // Dynamically allocate memory for initialSize integers
    array = (int *)malloc(initialSize * sizeof(int));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input initial elements
    printf("Enter %d elements:\n", initialSize);
    for (int i = 0; i < initialSize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Display initial elements
    printf("You entered the following elements:\n");
    for (int i = 0; i < initialSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Reallocate memory
    printf("Enter the new size of the array (greater than %d): ", initialSize);
    scanf("%d", &newSize);

    // Check if the new size is valid
    if (newSize <= initialSize) {
        printf("New size must be greater than the initial size.\n");
        free(array);
        return 1;
    }

    // Reallocate memory for newSize integers
    array = (int *)realloc(array, newSize * sizeof(int));

    // Check if memory reallocation was successful
    if (array == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Input additional elements
    printf("Enter %d additional elements:\n", newSize - initialSize);
    for (int i = initialSize; i < newSize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Display all elements
    printf("All elements after reallocation:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
