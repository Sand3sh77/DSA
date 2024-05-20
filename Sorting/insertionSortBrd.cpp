#include <stdio.h>

void InsertionSort(int A[],int size){
	int i,j,temp;
	
	for(i=1;i<size;i++){
			temp=A[i];
			j=i-1;
			while(j>=0 && A[j]>temp){
				A[j+1]=A[j];
				j=j-1;
			}
			A[j+1]=temp;
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
	InsertionSort(A,13);
	Display(A,13);
	return 0;
}