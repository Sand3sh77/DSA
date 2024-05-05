#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = value;
    return newNode;
}

void PUSH(struct Node **top, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}
void POP(struct Node **top)
{
    if (*top == NULL)
        printf("Stack is empty\n");
    else
    {
        struct Node *temp = *top;
        *top = temp->next;
        free(temp);
    }
}

void PEEK(struct Node *top)
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        printf("%d\n", top->data);
    }
}

int main()
{
    struct Node *stackTop = NULL;

    PUSH(&stackTop, 10);
    PUSH(&stackTop, 35);
    PUSH(&stackTop, 1234);
    PEEK(stackTop);
    POP(&stackTop);
    PEEK(stackTop);
    POP(&stackTop);
    PEEK(stackTop);
    POP(&stackTop);
    PEEK(stackTop);
    return 0;
}