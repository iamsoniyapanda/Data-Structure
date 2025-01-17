//Write a Menu driven C program to accomplish the following functionalities in Stack using Linked List: 
//a. Insert an element into the stack using a Linked List (Push Operation). 
//b. Delete an element from the stack using a Linked List (Pop Operation). 
//c. Return the value of the topmost element of the stack (without deleting it from the stack) using a Linked List. 
//d. Display the elements of the stack using a Linked List.
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the stack
struct Stack {
    struct Node* top;
};

// Function to initialize the stack
void initializeStack(struct Stack* s) {
    s->top = NULL;  // Set the top to NULL, indicating an empty stack
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == NULL;
}

// Push operation (insert an element into the stack)
void push(struct Stack* s, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}

// Pop operation (delete an element from the stack)
void pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        struct Node* temp = s->top;
        int poppedValue = temp->data;
        s->top = s->top->next;
        free(temp);
        printf("Popped %d from the stack.\n", poppedValue);
    }
}

// Top operation (view the topmost element of the stack without deleting it)
void top(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No top element to show.\n");
    } else {
        printf("Top element is %d.\n", s->top->data);
    }
}

// Display operation (display all elements in the stack)
void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = s->top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
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
