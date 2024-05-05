#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// Stack structure
typedef struct {
    int top;
    int items[STACK_SIZE];
} Stack;

// Stack functions
void push(Stack *s, int value) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

int evaluateExpression(char *expression, int A, int B, int C, int D) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == 'A') {
            push(&stack, A);
        } else if (expression[i] == 'B') {
            push(&stack, B);
        } else if (expression[i] == 'C') {
            push(&stack, C);
        } else if (expression[i] == 'D') {
            push(&stack, D);
        } else if (expression[i] == '*') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            push(&stack, operand1 * operand2);
        } else if (expression[i] == '+') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            push(&stack, operand1 + operand2);
        } else if (expression[i] == '-') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            push(&stack, operand1 - operand2);
        }
    }

    return pop(&stack);
}

int main() {
    int A = 5, B = 4, C = 3, D = 7;
    char expression[] = "ABCD-*+";

    int result = evaluateExpression(expression, A, B, C, D);
    printf("Result of the expression: %d\n", result);

    return 0;
}
