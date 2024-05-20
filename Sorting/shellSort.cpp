#include <stdio.h>

void ShellSort(int A[],int n){
	int gap,i,j;
	
	for(gap=n/2;gap>0;gap=gap/2){
		for(j=gap;j<n;j++){
			for(i=j-gap;i>=0;i=i-gap){
				if(A[i+gap]<A[i]){
					int temp=A[i+gap];
					A[i+gap]=A[i];
					A[i]=temp;
				}
				else
					break;
			}
		}
	}
	
}

void shellSort(int A[],int n){
	int gap,i,j;
	
	for(gap=n/2;gap>0;gap=gap/2){
		for(j=gap;j<n;j++){
			for(i=j-gap;i>=0;i=i-gap){
				if(A[i+gap]<A[i]){
					int temp=A[i];
					A[i]=A[i+gap];
					A[i+gap]=temp;
				}
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
	shellSort(A,13);
	Display(A,13);
	return 0;
}