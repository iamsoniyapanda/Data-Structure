//A program to find the second largest of n numbers using an array
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int *array;   // Pointer to the array
    int n;        // Number of elements
    int largest, secondLargest; // Variables to store the largest and second largest numbers

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Check if the number of elements is valid
    if (n < 2) {
        printf("There must be at least two elements to find the second largest number.\n");
        return 1;
    }

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

    // Initialize largest and secondLargest
    largest = secondLargest = INT_MIN;

    // Find the largest and second largest numbers
    for (int i = 0; i < n; i++) {
        if (array[i] > largest) {
            secondLargest = largest; // Update second largest
            largest = array[i]; // Update largest
        } else if (array[i] > secondLargest && array[i] != largest) {
            secondLargest = array[i]; // Update second largest
        }
    }

    // Check if second largest was found
    if (secondLargest == INT_MIN) {
        printf("There is no second largest number. All elements might be the same.\n");
    } else {
        printf("The second largest number is %d.\n", secondLargest);
    }

    // Free the allocated memory
    free(array);

    return 0;
}
