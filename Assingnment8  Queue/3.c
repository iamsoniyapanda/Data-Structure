//Write a Menu driven C program to accomplish the following functionalities in Circular Queue using Array: 
//a.Insert an element into the circular queue. 
//b.Delete an element from the circular queue. 
//c.Return the value of the FRONT element of the circular queue (without deleting it from the queue).  
//d.Display the elements of a circular queue using the circular queue.
#include <stdio.h>
#define MAX 5  // Maximum size of the circular queue

// Structure to represent a circular queue
struct CircularQueue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the circular queue
void initializeQueue(struct CircularQueue* q) {
    q->front = q->rear = -1;  // Both front and rear are -1, indicating an empty queue
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

// Enqueue operation (insert an element into the circular queue)
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert %d\n", value);
    } else {
        if (q->front == -1) {  // If the queue is empty, set front to 0
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;  // Circular increment of rear
        q->arr[q->rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Dequeue operation (delete an element from the circular queue)
void dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot perform dequeue.\n");
    } else {
        int dequeuedValue = q->arr[q->front];
        printf("Dequeued %d from the queue.\n", dequeuedValue);
        
        if (q->front == q->rear) {  // If the queue has only one element, reset the queue
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;  // Circular increment of front
        }
    }
}

// Peep operation (view the front element without deleting it)
void peep(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No front element to show.\n");
    } else {
        printf("Front element is %d.\n", q->arr[q->front]);
    }
}

// Display the elements in the circular queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;  // Circular increment of index
        }
        printf("%d\n", q->arr[q->rear]);  // Print the last element (rear)
    }
}

// Main function to drive the menu
int main() {
    struct CircularQueue q;
    initializeQueue(&q);

    int choice, value;

    while (1) {
        // Menu
        printf("\nCircular Queue Operations Menu:\n");
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
