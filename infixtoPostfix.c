#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

// Function prototypes
void push(Stack *s, char c);
char pop(Stack *s);
int precedence(char op);
void infixToPostfix(char *infix, char *postfix);

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character from input

    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Function to push an item onto the stack
void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = c;
}

// Function to pop an item from the stack
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

// Function to determine the precedence of an operator
int precedence(char op) {
    switch(op) {
    	
    	case '^':
    		return 3;
    		
        case '*':
        case '/':
            return 2;
            
        case '+':
        case '-':
            return 1;
            
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    stack.top = -1;
    int i, j = 0;
    char token, popped;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while ((popped = pop(&stack)) != '(') {
                postfix[j++] = popped;
            }
        } else { // Operator encountered
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }
    
    // Pop any remaining operators from the stack
    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }
    
    postfix[j] = '\0'; // Null-terminate the postfix expression
}
