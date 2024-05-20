#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct stack
{
    int arr[MAX_SIZE];
    int top;
};
typedef struct stack *st;

void initialize(struct stack *s)
{
    s->top = -1;
}

bool isEmpty(struct stack *s)
{
    return s->top == -1;
}

bool isFull(struct stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void PUSH(struct stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack is full");
        return;
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

void POP(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("%d\n", s->arr[s->top]);
        s->arr[s->top] = 0;
        s->top--;
    }
};

void display(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("No data to display");
    }
    else
    {
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d\t", s->arr[i]);
        }
    }
}

int main()
{
    struct stack s1; // No need to use pointer
    initialize(&s1); // Pass the address of s1
    PUSH(&s1, 1);
    PUSH(&s1, 55);
    POP(&s1);
    display(&s1);
    return 0;
}
