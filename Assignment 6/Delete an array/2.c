//A program to delete a number from a sorted array
#include <stdio.h>
#define MAX_SIZE 100
void deleteFromSortedAsc(int arr[], int *size, int num) {
    int i, j;
    
    // Find the position of the number to delete
    for (i = 0; i < *size; i++) {
        if (arr[i] == num) {
            break;
        }
    }
    if (i == *size) {
        printf("Error: Number not found in the array.\n");
        return;
    }
    for (j = i; j < *size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    (*size)--;
}

int main() {
    int arr[MAX_SIZE] = {1, 3, 5, 7, 9}; // Example sorted array
    int size = 5; // Current size of the array
    int num;

    // Get the number to delete from the user
    printf("Enter the number to delete: ");
    scanf("%d", &num);

    // Delete the number from the sorted array
    deleteFromSortedAsc(arr, &size, num);

    // Print the updated array
    printf("Array after deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
