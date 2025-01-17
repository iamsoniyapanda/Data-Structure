//Write a Menu driven C program to accomplish the following functionalities in Stack using an Array: 
//a. Insert an element into the stack using an array (Push Operation). 
//b. Delete an element from the stack using an array (Pop Operation). 
//c. Return the value of the topmost element of the stack (without deleting it from the stack) using an array. 
//d. Display the elements of a stack using an array.
#include <stdio.h>
#define MAX 5  // Maximum size of the stack

// Structure to represent a stack
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack* s) {
    s->top = -1;  // Set the top to -1, indicating an empty stack
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push operation (insert an element into the stack)
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d\n", value);
    } else {
        s->arr[++(s->top)] = value;  // Increment top and insert the value
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Pop operation (delete an element from the stack)
void pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        int poppedValue = s->arr[s->top];
        s->top--;  // Decrement the top pointer
        printf("Popped %d from the stack.\n", poppedValue);
    }
}

// Top operation (view the topmost element of the stack without deleting it)
void top(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No top element to show.\n");
    } else {
        printf("Top element is %d.\n", s->arr[s->top]);
    }
}

// Display the elements in the stack
void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

// Main function to drive the menu
int main() {
    struct Stack s;
    initializeStack(&s);

    int choice, value;

    while (1) {
        // Menu
        printf("\nStack Operations Menu:\n");
        printf("1. Push (Insert an element)\n");
        printf("2. Pop (Delete an element)\n");
        printf("3. Top (View the topmost element)\n");
        printf("4. Display the stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                top(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
