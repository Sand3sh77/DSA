#include <stdio.h>

int binarySearch(int A[], int L, int H, int key)
{
    if (L <= H)
    {
        int mid = (L + H )/ 2;

        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return binarySearch(A, L, mid - 1, key);
        else
            return binarySearch(A, mid + 1, H, key);
    }
    return -1;
}

int main()
{
    int A[] = {12, 45, 55, 78, 99};
    int B[] = {1, 455, 544, 636, 888};

    int result=binarySearch(B,0,4,544);

    printf("\n\nThe result is %d",result);
    return 0;
}