#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){
	int arr[1000],sum=0;
	int i;
	for( i=0;i<1000;i++){
		scanf("%d",&arr[i]);
	}
	
	#pragma omp parallel for reduction(+ :sum)
	for (i=0;i<1000;i++){
		sum += arr[i];
	}
	
	printf("Sum of array: %d",sum);
	return 0;
}
