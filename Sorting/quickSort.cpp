#include <stdio.h>

int partition(int A[],int l,int r){
	
	int key=A[l];
	int count=0;
	
	for(int i=l+1;i<=r;i++){
		if(A[i]<=key)
		count++;
	}
	
	int keyIndex=l+count;
	
	int temp=A[keyIndex];
	A[keyIndex]=A[l];
	A[l]=temp;
	
	int i=l,j=r;
	
	while(i<keyIndex && j>keyIndex){
		while(A[j]>key)
			j--;
		while(A[i]<=key)
			i++;
		if(i<keyIndex && j>keyIndex){
			temp=A[i];
			A[i++]=A[j];
			A[j++]=temp;
		}	
	}
	return keyIndex;
}



void QuickSort(int A[],int l,int r){
	if(l<r){
		int p=partition(A,l,r);
		QuickSort(A,l,p-1);
		QuickSort(A,p+1,r);
	}
}

void Display(int A[],int size){
	for(int i=0;i<size;i++){
		printf("%d\t",A[i]);
	}
	printf("\n");
}

int main(){
	int A[]={5,2,654,65,24,2940,25,2,12,42,42,24,124};
	Display(A,13);
	QuickSort(A,0,12);
	Display(A,13);
	return 0;
}