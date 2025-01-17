//Write a program to convert an infix expression into its equivalent postfix notation.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
    } else {
        stack->arr[++stack->top] = value;
    }
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 to indicate an error
    } else {
        return stack->arr[stack->top--];
    }
}

// Function to peek the top element of the stack
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

// Function to check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        // If current character is an operand, add it to the postfix expression
        if (isalnum(current)) {
            postfix[k++] = current;
        }
        // If current character is '(', push it to the stack
        else if (current == '(') {
            push(&stack, current);
        }
        // If current character is ')', pop and add to postfix until '(' is encountered
        else if (current == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);  // Pop '('
        }
        // If current character is an operator
        else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(current)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, current);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0';  // Null-terminate the postfix string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove trailing newline character from fgets
    int len = 0;
    while (infix[len] != '\0') {
        len++;
    }
    if (infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
