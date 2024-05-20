#include <stdio.h>

int linearSearch(int A[], int key, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (key == A[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int A[] = {12, 13, 23, 76, 22};
    int B[] = {234, 463, 463234, 2341, 213};

    int result = linearSearch(B,463, 5);

    printf("\nThe result is %d", result);
    return 0;
}