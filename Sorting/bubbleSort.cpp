#include <stdio.h>

void BubbleSort(int A[],int size){
	int i,j;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(A[j]>A[j+1]){
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
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
	BubbleSort(A,13);
	Display(A,13);
	return 0;
}