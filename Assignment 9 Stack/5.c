//Write a program to evaluate a postfix expression. 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];
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
void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack->arr[++(stack->top)] = value;
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 to indicate an error
    } else {
        return stack->arr[stack->top--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];

        // If the current character is a digit, push it onto the stack
        if (isdigit(current)) {
            int num = current - '0';  // Convert char to integer
            push(&stack, num);
        }
        // If the current character is an operator
        else if (current == '+' || current == '-' || current == '*' || current == '/' || current == '^') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            // Perform the operation based on the operator
            switch (current) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);  // Power operation
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }

            // Push the result of the operation onto the stack
            push(&stack, result);
        }
    }

    // At the end, the stack should contain only one element, which is the result
    return pop(&stack);
}

int main() {
    char expression[MAX];

    printf("Enter a postfix expression: ");
    fgets(expression, MAX, stdin);

    // Remove trailing newline if present
    int len = strlen(expression);
    if (expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}

