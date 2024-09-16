//Write a Menu driven C program to accomplish the following functionalities in circular linked list:
//a) Create a circular linked list
//b) Display the elements of a circular linked list
//c) Insert a node at the beginning of a circular linked list
//d) Insert a node at the end of a circular linked list
//e) Delete a node from the beginning of a circular linked list
//f) Delete a node from the end of a circular linked list
//g) Delete a node after a given node of a circular linked list
//h) Delete the entire circular linked list
#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function prototypes
void createList(Node **head);
void displayList(Node *head);
void insertAtBeginning(Node **head, int data);
void insertAtEnd(Node **head, int data);
void deleteFromBeginning(Node **head);
void deleteFromEnd(Node **head);
void deleteAfterNode(Node **head, int target);
void deleteList(Node **head);

int main() {
    Node *head = NULL;
    int choice, data, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a circular linked list\n");
        printf("2. Display the elements of the circular linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire circular linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 5:
                deleteFromBeginning(&head);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                printf("Enter target node data: ");
                scanf("%d", &target);
                deleteAfterNode(&head, target);
                break;
            case 8:
                deleteList(&head);
                break;
            case 9:
                deleteList(&head);
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to create a circular linked list
void createList(Node **head) {
    Node *newNode, *temp;
    int data, n, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
            newNode->next = *head;
        } else {
            temp = *head;
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = *head;
        }
    }
}

// Function to display the circular linked list
void displayList(Node *head) {
    Node *temp = head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        newNode->next = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the beginning
void deleteFromBeginning(Node **head) {
    Node *temp = *head;

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
    }
}

// Function to delete a node from the end
void deleteFromEnd(Node **head) {
    Node *temp = *head;
    Node *prev = NULL;

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}

// Function to delete a node after a given node
void deleteAfterNode(Node **head, int target) {
    Node *temp = *head;
    Node *nodeToDelete = NULL;

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    do {
        if (temp->data == target) {
            nodeToDelete = temp->next;
            if (nodeToDelete == *head) {
                printf("No node after the target node.\n");
                return;
            }
            temp->next = nodeToDelete->next;
            free(nodeToDelete);
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Node with data %d not found.\n", target);
}

// Function to delete the entire circular linked list
void deleteList(Node **head) {
    Node *temp = *head;
    Node *nextNode;

    if (*head == NULL) {
        return;
    }

    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != *head);

    *head = NULL;
}
