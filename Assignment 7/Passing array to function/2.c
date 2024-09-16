// a program to interchange the largest & smallest number in an array (use the concept of passing an array to a function)
#include <stdio.h>
void interchangeLargestAndSmallest(int arr[], int size);
void findSmallestAndLargest(int arr[], int size, int *smallest, int *largest);

int main() {
    int arr[100]; 
    int n;
    printf("Enter the number of elements (up to 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Error: Number of elements must be between 1 and 100.\n");
        return 1;
    }

    // Read the array elements
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Interchange the largest and smallest numbers
    interchangeLargestAndSmallest(arr, n);

    // Print the updated array
    printf("Array after interchanging the largest and smallest numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Function to interchange the largest and smallest numbers in the array
void interchangeLargestAndSmallest(int arr[], int size) {
    int smallest, largest;
    int smallestIndex, largestIndex;
    
    // Find the smallest and largest numbers and their indices
    findSmallestAndLargest(arr, size, &smallest, &largest);
    
    // Find the indices of the smallest and largest numbers
    for (int i = 0; i < size; i++) {
        if (arr[i] == smallest) {
            smallestIndex = i;
        }
        if (arr[i] == largest) {
            largestIndex = i;
        }
    }
    
    // Swap the smallest and largest numbers
    arr[smallestIndex] = largest;
    arr[largestIndex] = smallest;
}

// Function to find the smallest and largest numbers in the array
void findSmallestAndLargest(int arr[], int size, int *smallest, int *largest) {
    *smallest = *largest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *smallest) {
            *smallest = arr[i];
        }
        if (arr[i] > *largest) {
            *largest = arr[i];
        }
    }
}
