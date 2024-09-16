//To print the largest and second largest elements of the array
#include <stdio.h>
#include <limits.h> 
void findLargestAndSecondLargest(const int arr[], int size, int *largest, int *secondLargest);

int main() {
    int array[] = {34, 78, 12, 89, 56, 23, 45};
    int size = sizeof(array) / sizeof(array[0]);
    int largest, secondLargest;

    // Find largest and second largest elements
    findLargestAndSecondLargest(array, size, &largest, &secondLargest);

    // Print the results
    printf("The largest element is %d.\n", largest);
    printf("The second largest element is %d.\n", secondLargest);

    return 0;
}

// Function to find the largest and second largest elements in an array
void findLargestAndSecondLargest(const int arr[], int size, int *largest, int *secondLargest) {
    if (size < 2) {
        printf("Array should contain at least two elements.\n");
        return;
    }

    // Initialize largest and secondLargest
    *largest = INT_MIN;
    *secondLargest = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > *largest) {
            *secondLargest = *largest;
            *largest = arr[i];
        } else if (arr[i] > *secondLargest && arr[i] != *largest) {
            *secondLargest = arr[i];
        }
    }

    // If the second largest is still INT_MIN, it means there was no second distinct largest element
    if (*secondLargest == INT_MIN) {
        printf("There is no distinct second largest element.\n");
    }
}
