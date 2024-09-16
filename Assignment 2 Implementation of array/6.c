 //A program to display n number of elements.memory should be alloacted dynamically using malloc()
#include <stdio.h>
#include <stdlib.h>  // For malloc() and free()

int main() {
    int *array;
    int n;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n integers
    array = (int *)malloc(n * sizeof(int));
    
    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements into the allocated memory
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Display the elements
    printf("You entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
