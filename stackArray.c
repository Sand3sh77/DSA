#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

bool isFull()
{
    if (top <= SIZE - 1)
        return false;
    return true;
}

bool isEmpty()
{
    if (top == -1)
        return true;
    return false;
}

void PUSH(int data)
{
    if (isFull())
        printf("The stack is full\n");
    else
    {
        top++;
        stack[top] = data;
    }
}

void POP()
{
    if (isEmpty())
        printf("The stack is empty\n");
    else
    {
        top--;
    }
}

void PEEK()
{
    if (isEmpty())
        printf("The stack is empty\n");
    else
    {
        printf("%d\n", stack[top]);
    }
}

int main()
{
    PEEK();
    PUSH(10);
    PUSH(11);
    PUSH(51);
    PEEK();
    POP();
    PEEK();
    return 0;
}