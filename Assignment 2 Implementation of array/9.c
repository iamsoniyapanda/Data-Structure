//A program to search an elements in an array using dyanamic memory allocation
#include <stdio.h>
#include <stdlib.h>  // For malloc(), free()

// Function prototypes
void inputArray(int *array, int size);
int searchElement(int *array, int size, int key);

int main() {
    int *array;
    int size, key, index;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Dynamically allocate memory for size integers
    array = (int *)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements into the allocated memory
    printf("Enter %d elements:\n", size);
    inputArray(array, size);

    // Input the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &key);

    // Search for the element
    index = searchElement(array, size, key);

    // Display the result
    if (index != -1) {
        printf("Element %d found at index %d.\n", key, index);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    // Free the allocated memory
    free(array);

    return 0;
}

// Function to input array elements
void inputArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

// Function to search for an element in the array
int searchElement(int *array, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;  // Element found, return index
        }
    }
    return -1;  // Element not found, return -1
}
