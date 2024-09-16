// A program to pass an array to a function using  call by value ,update the array value in the function ,print the array elements both in the function and in the calling function
#include <stdio.h>
#include <string.h>

#define SIZE 5
void updateArray(int arr[], int size);
void printArray(const int arr[], int size);

int main() {
    int array[SIZE] = {1, 2, 3, 4, 5};

    // Print the original array
    printf("Original array in main:\n");
    printArray(array, SIZE);

    // Pass the array to the function
    updateArray(array, SIZE);

    // Print the array after the function call
    printf("Array after updateArray function:\n");
    printArray(array, SIZE);

    return 0;
}

// Function to update the array
void updateArray(int arr[], int size) {
    printf("Array inside updateArray function before update:\n");
    printArray(arr, size);

    // Update array values
    for (int i = 0; i < size; i++) {
        arr[i] += 10;  // Adding 10 to each element
    }

    printf("Array inside updateArray function after update:\n");
    printArray(arr, size);
}

// Function to print array elements
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
