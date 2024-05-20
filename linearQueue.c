#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = 0, rear = -1;

bool isEmpty()
{
    if (rear == -1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if (rear == MAX_SIZE - 1)
    {
        return true;
    }
    return false;
}

void Enqueue(int data)
{
    if (isFull())
    {
        printf("The queue is already full");
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

void Dequeue()
{
    if (isEmpty())
    {
        printf("The queue is empty");
    }
    else
    {
        printf("Dequed : %d\n", queue[front]);
        queue[front] = NULL;
        front++;
    }
}

void Traverse()
{
    if (isEmpty())
    {
        printf("The queue is empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d \t", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    Enqueue(55);
    Enqueue(1);
    Enqueue(32);
    Traverse();
    Dequeue();
    Dequeue();
    Traverse();
    return 0;
}