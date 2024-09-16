//A program to find the mean of n numbers using array
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array; // Pointer to the array
    int n;      // Number of elements
    int sum = 0; // Variable to store the sum of elements
    float mean; // Variable to store the mean

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
        sum += array[i]; // Add each element to sum
    }

    // Calculate the mean
    mean = (float)sum / n;

    // Display the mean
    printf("The mean of the entered numbers is: %.2f\n", mean);

    // Free the allocated memory
    free(array);

    return 0;
}
