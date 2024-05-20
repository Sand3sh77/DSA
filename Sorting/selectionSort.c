#include <stdio.h>

int *selectionSort(int A[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        int min = i;
        for (j = i; j < size; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
    return A;
}

int main()
{

    int i;
    int A[] = {9, 7, 5, 3, -4, 1};

    for (i = 0; i < 6; i++)
    {
        printf("%d\t", A[i]);
    }

    printf("\n");
    int *result = selectionSort(A, 6);

    for (i = 0; i < 6; i++)
    {
        printf("%d\t", result[i]);
    }

    return 0;
}