 //Write a Menu driven C program to accomplish the following functionalities in Queue using Linked List: 
//a. Insert an element into the queue using a Linked List (Enqueue Operation).  
//b.Delete an element from the queue using a Linked List (Dequeue Operation). 
//c. Return the value of the FRONT element of the queue (without deleting it from the queue) using a Linked List (Peep operation). 
//d. Display the elements of a queue using a Linked List.
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a queue using linked list
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Enqueue operation (insert an element into the queue)
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Inserted %d into the queue.\n", value);
}

// Dequeue operation (delete an element from the queue)
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot perform dequeue.\n");
    } else {
        struct Node* temp = q->front;
        int dequeuedValue = temp->data;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL; // If the queue becomes empty, set rear to NULL
        }
        free(temp);
        printf("Dequeued %d from the queue.\n", dequeuedValue);
    }
}

// Peep operation (view the front element without deleting it)
void peep(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No front element to show.\n");
    } else {
        printf("Front element is %d.\n", q->front->data);
    }
}

// Display the elements in the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = q->front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to drive the menu
int main() {
    struct Queue q;
    initializeQueue(&q);

    int choice, value;

    while (1) {
        // Menu
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue (Insert an element)\n");
        printf("2. Dequeue (Delete an element)\n");
        printf("3. Peep (View the front element)\n");
        printf("4. Display the queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peep(&q);
                break;
            case 4:
                display(&q);
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
