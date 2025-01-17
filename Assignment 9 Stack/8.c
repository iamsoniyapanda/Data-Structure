//Write a program to solve the tower of Hanoi problem using recursion
#include <stdio.h>

// Function to move disks from source to destination
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;

    // Ask the user for the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Call the function to solve the Tower of Hanoi
    printf("Steps to solve Tower of Hanoi for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
