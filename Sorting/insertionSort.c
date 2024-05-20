#include <stdio.h>

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && key < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {3254, 54, 64, 23};
    display(A, 4);
    InsertionSort(A, 4);
    display(A, 4);
    return 0;
}