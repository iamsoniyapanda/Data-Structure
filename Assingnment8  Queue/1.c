//Write a Menu driven C program to accomplish the following functionalities in Queue using an Array: 
//a. Insert an element into the queue using an array (Enqueue Operation). 
//b. Delete an element from the queue using an array (Dequeue Operation). 
//c. Return the value of the FRONT element of the queue (without deleting it from the queue) using an array (Peep operation). 
//d. Display the elements of a queue using an array. 
#include <stdio.h>
#define MAX 5  // Maximum size of the queue

// Structure to represent a queue
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Enqueue operation (insert an element into the queue)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;  // Set front to 0 if the queue is empty
        }
        q->rear++;
        q->arr[q->rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Dequeue operation (delete an element from the queue)
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot perform dequeue.\n");
    } else {
        int dequeuedValue = q->arr[q->front];
        printf("Dequeued %d from the queue.\n", dequeuedValue);
        
        if (q->front == q->rear) {
            q->front = q->rear = -1;  // Reset the queue when it becomes empty
        } else {
            q->front++;
        }
    }
}

// Peep operation (view the front element without deleting it)
void peep(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No front element to show.\n");
    } else {
        printf("Front element is %d.\n", q->arr[q->front]);
    }
}

// Display the elements in the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
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
