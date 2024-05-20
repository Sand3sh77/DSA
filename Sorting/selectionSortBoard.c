#include <stdio.h>

void SelectionSort(int A[],int size){
	int i,j;
	
	for(i=0;i<size-1;i++){
		int sm=A[i];
		int index=i;
		for(j=i+1;j<size;j++){
			if(A[j]<sm){
				sm=A[j];
				index=j;
			}
		}
		int temp=A[i];
		A[i]=sm;
		A[index]=temp;
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
	SelectionSort(A,13);
	Display(A,13);
	return 0;
}