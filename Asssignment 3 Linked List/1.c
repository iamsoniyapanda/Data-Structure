//Write a Menu driven C program to accomplish the following functionalities in single linked list:
//a) Create a single linked list
//b) Display the elements of a single linked list
//c) Insert a node at the beginning of a single linked list
//d) Insert a node at the end of a single linked list
//e) Insert a node before a given node of a single linked list
//f) Insert a node after a given node of a single linked list
//g) Delete a node from the beginning of a single linked list
//h) Delete a node from the end of a single linked list
//i) Delete a node after a given node of a single linked list
//j) Delete the entire single linked list
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

void createList(Node **head);
void displayList(Node *head);
void insertAtBeginning(Node **head, int data);
void insertAtEnd(Node **head, int data);
void insertBeforeNode(Node **head, int target, int data);
void insertAfterNode(Node **head, int target, int data);
void deleteFromBeginning(Node **head);
void deleteFromEnd(Node **head);
void deleteAfterNode(Node **head, int target);
void deleteList(Node **head);

int main() {
    Node *head = NULL;
    int choice, data, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a single linked list\n");
        printf("2. Display the elements of the linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire linked list\n");
        printf("11. Exit\n");
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
                printf("Enter target node data: ");
                scanf("%d", &target);
                printf("Enter data to insert before %d: ", target);
                scanf("%d", &data);
                insertBeforeNode(&head, target, data);
                break;
            case 6:
                printf("Enter target node data: ");
                scanf("%d", &target);
                printf("Enter data to insert after %d: ", target);
                scanf("%d", &data);
                insertAfterNode(&head, target, data);
                break;
            case 7:
                deleteFromBeginning(&head);
                break;
            case 8:
                deleteFromEnd(&head);
                break;
            case 9:
                printf("Enter target node data: ");
                scanf("%d", &target);
                deleteAfterNode(&head, target);
                break;
            case 10:
                deleteList(&head);
                break;
            case 11:
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

// Function to create a linked list
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
        } else {
            temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Function to display the linked list
void displayList(Node *head) {
    Node *temp = head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node before a given node
void insertBeforeNode(Node **head, int target, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    Node *prev = NULL;
    newNode->data = data;

    if (*head == NULL) {
        printf("The list is empty.\n");
        free(newNode);
        return;
    }

    if (temp->data == target) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", target);
        free(newNode);
        return;
    }

    newNode->next = temp;
    prev->next = newNode;
}

// Function to insert a node after a given node
void insertAfterNode(Node **head, int target, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    newNode->data = data;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", target);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the beginning
void deleteFromBeginning(Node **head) {
    Node *temp;

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(Node **head) {
    Node *temp = *head;
    Node *prev = NULL;

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (temp->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    free(temp);
    prev->next = NULL;
}

// Function to delete a node after a given node
void deleteAfterNode(Node **head, int target) {
    Node *temp = *head;
    Node *nodeToDelete;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Node with data %d not found or has no node after it.\n", target);
        return;
    }

    nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Function to delete the entire linked list
void deleteList(Node **head) {
    Node *temp;
    
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
