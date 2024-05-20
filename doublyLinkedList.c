#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node nd;
struct node *head = NULL;

int insertAtBeg(int data)
{
    nd *newnode = (struct node *)malloc(sizeof(nd));
    newnode->data = data;
    newnode->prev = newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void deleteAtBeg()
{
    if (head == NULL)
    {
        printf("No data to delete");
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
}

void insertAtEnd(int data)
{
    nd *newnode = (struct node *)malloc(sizeof(nd));
    newnode->data = data;
    newnode->next = newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        nd *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        nd *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next->prev = NULL;
        temp->next = NULL;
    }
}

void deleteAtPos(int pos)
{
    if (head == NULL)
    {
        printf("Empty LL");
    }
    else
    {
        if (pos < 1)
        {
            printf("Posn should be greater than 0");
        }
        else if (pos == 1)
        {
            deleteAtBeg();
        }
        else
        {
            nd *temp = head;
            for (int i = 1; i < pos - 1 && temp != NULL; i++)
            {
                temp = temp->next;
            }
            if (temp != NULL)
            {
                if (temp->next->next != NULL)
                {
                    temp->next = temp->next->next;
                    temp->next->prev = temp;
                }
                else
                    temp->next = NULL;
            }
            else
            {
                printf("Invalid Posn");
            }
        }
    }
}

void insertAtPos(int data, int pos)
{
    nd *newnode = (nd *)malloc(sizeof(nd));
    newnode->data = data;
    newnode->next = newnode->prev = NULL;
    if (pos < 1)
    {
        printf("Position should be greater than 0");
    }
    else if (pos == 1)
    {
        insertAtBeg(data);
    }
    else
    {
        int i;
        nd *temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }
        else
        {
            printf("Invalid Position\n");
        }
    }
}

void displayForward()
{
    if (head == NULL)
    {
        printf("Empty LL");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    insertAtBeg(20);
    insertAtBeg(40);
    insertAtBeg(10);
    insertAtEnd(2);
    insertAtPos(34, 4);
    deleteAtBeg();
    deleteAtEnd();
    deleteAtPos(2);
    displayForward();
    return 0;
}
