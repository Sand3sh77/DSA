#include <stdio.h>

int *bubbleSort(int A[], int size)
{

    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size-i-1; j++)
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
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
    int *result = bubbleSort(A, 6);

    for (i = 0; i < 6; i++)
    {
        printf("%d\t", result[i]);
    }

    return 0;
}