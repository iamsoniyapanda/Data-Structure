// Write a program to convert an infix expression into its equivalent prefix notation. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Function to push an element onto the stack
void push(struct Stack* stack, char value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack->arr[++(stack->top)] = value;
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

// Function to reverse a string
void reverse(char* expr) {
    int n = strlen(expr);
    for (int i = 0; i < n / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[n - i - 1];
        expr[n - i - 1] = temp;
    }
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

// Function to convert infix expression to prefix
void infixToPrefix(char* infix, char* prefix) {
    // Step 1: Reverse the infix expression
    reverse(infix);

    // Step 2: Change parentheses to opposite
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Step 3: Convert the modified infix to postfix
    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Step 4: Reverse the postfix expression to get the prefix expression
    reverse(postfix);

    // Copy the final result into prefix
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove the trailing newline character
    int len = strlen(infix);
    if (infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
