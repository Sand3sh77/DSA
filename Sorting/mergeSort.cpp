#include <stdio.h>

void merge(int A[],int l,int m,int r){
	int n1=m-l+1;
	int n2=r-m;
	
	int arr1[n1],arr2[n2];
	
	for(int i=0;i<n1;i++)
		arr1[i]=A[l+i];
	for(int i=0;i<n2;i++)
		arr2[i]=A[m+1+i];
		
	int i=0,j=0,k=l;
		
	while(i<n1 && j<n2){
		if(arr1[i]<=arr2[j])
			A[k++]=arr1[i++];
		else
			A[k++]=arr2[j++];
	}	
	
	while(i<n1)
		A[k++]=arr1[i++];
	while(j<n2)
		A[k++]=arr2[j++];
}

void MergeSort(int A[],int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		
		MergeSort(A,l,mid);
		MergeSort(A,mid+1,r);
		merge(A,l,mid,r);
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

int main(){
	int A[]={214,455,4,5,765,87687,54,564,42,234};
	display(A,10);
	MergeSort(A,0,9);
	display(A,10);
	return 0;
}