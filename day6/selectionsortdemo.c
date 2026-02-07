//Program to implement selection sort algorithm
#include <stdio.h>
#include <stdlib.h>
void readArray(int a[], int n){
	for (int i =0;i<n; scanf("%d", &a[i++]));
}
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
//implementing selection sort algorithm
void selectionSort(int a[], int n){
	for (int i = 0; i<n; i++){
		int minIndex = i;
		for (int j = i+1; j<n; j++ ){
			if (a[j]<a[minIndex]) 
				minIndex = j;
		}
		if (minIndex != i)
			swap(a+minIndex, a+i);
	}
}
void printArray(int a[], int n){
	printf("\n[");
	for (int i = 0; i<n-1; printf("%d,", a[i++]));
	printf("%d]", a[n-1]);
}
int main(){
	int size, *arr;
	scanf("%d", &size);
	arr = (int*)malloc(sizeof(int)*size);
	//reading list of elements from the user
	readArray(arr, size);
	selectionSort(arr, size);
	printArray(arr, size);
	return 0;
}