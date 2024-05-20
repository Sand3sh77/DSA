#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define SIZE 3

struct queue
{
    int array[SIZE];
    int rear;
    int front;
    int c;
};
typedef struct queue cq;

cq *initialize()
{
    cq *q = (cq *)malloc(sizeof(cq));
    q->rear = SIZE - 1;
    q->front = SIZE - 1;
    q->c = 0;
    return q;
}

bool isFull(cq *q)
{
    if (q->c == SIZE)
    {
        return true;
    }
    return false;
}

bool isEmpty(cq *q)
{
    if (q->c == 0)
    {
        return true;
    }
    return false;
}

void Enqueue(cq *q, int value)
{
    if (isFull(q))
    {
        printf("The queue is full");
    }
    else
    {
        q->rear = (q->rear + 1) % SIZE;
        q->array[q->rear] = value;
        q->c++;
    }
}

void Dequeue(cq *q)
{
    if (isEmpty(q))
        printf("The queue is empty");
    else
    {
        printf("dequed: %d\n", q->array[q->front]);
        q->front = (q->front + 1) % SIZE;
        q->c--;
    }
}

void Display(cq *q)
{
    if (isEmpty(q))
        printf("The queue is empty");
    else
    {
        for (int i = SIZE - q->c; i < q->c; i++)
        {
            printf("%d\t", q->array[i]);
        }
        printf("\n");
    }
}

int main()
{
    cq *q1 = initialize();
    Enqueue(q1, 5);
    Enqueue(q1, 10);
    Enqueue(q1, 2);
    Display(q1);
    Dequeue(q1);
    Dequeue(q1);
    Display(q1);
    return 0;
}
