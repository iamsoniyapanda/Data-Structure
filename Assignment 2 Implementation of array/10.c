// A program to allocate memoty using calloc() & then reallocate the previously allocated memory using realloca() .display the elements which have been taken after reallocation 
#include <stdio.h>
#include <stdlib.h>  // For calloc(), realloc(), and free()

int main() {
    int *array;
    int initialSize, newSize;

    // Input the number of initial elements
    printf("Enter the number of initial elements: ");
    scanf("%d", &initialSize);

    // Dynamically allocate memory for initialSize integers using calloc
    array = (int *)calloc(initialSize, sizeof(int));
    
    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input initial elements
    printf("Enter %d initial elements:\n", initialSize);
    for (int i = 0; i < initialSize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Display initial elements
    printf("Initial elements:\n");
    for (int i = 0; i < initialSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Input the new size of the array
    printf("Enter the new size of the array (greater than %d): ", initialSize);
    scanf("%d", &newSize);

    // Check if the new size is valid
    if (newSize <= initialSize) {
        printf("New size must be greater than the initial size.\n");
        free(array);
        return 1;
    }

    // Reallocate memory for newSize integers using realloc
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

    // Display all elements after reallocation
    printf("All elements after reallocation:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
