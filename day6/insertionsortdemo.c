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
//implementing insertion sort algorithm
void insertionSort(int a[], int n){
	for (int i = 1; i<n;i++){
		int key = a[i], j;
		for (j = i-1;j>=0 && key<a[j]; j-- ){
			a[j+1]= a[j];
		}
		a[j+1]=key;
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
	insertionSort(arr, size);
	printArray(arr, size);
	return 0;
}