//A program in c to read an array of n numbers & then find the smallest number(use the concept of passing an array to a function) 
#include <stdio.h>
int findSmallest(int arr[], int size);

int main() {
    int arr[100]; // Array to hold the numbers
    int n, i, smallest;

    // Read the number of elements
    printf("Enter the number of elements (up to 100): ");
    scanf("%d", &n);

    // Validate the number of elements
    if (n <= 0 || n > 100) {
        printf("Error: Number of elements must be between 1 and 100.\n");
        return 1;
    }

    // Read the array elements
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the smallest number using the function
    smallest = findSmallest(arr, n);

    // Print the smallest number
    printf("The smallest number in the array is: %d\n", smallest);

    return 0;
}

// Function to find the smallest number in an array
int findSmallest(int arr[], int size) {
    int min = arr[0]; // Initialize min with the first element
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
