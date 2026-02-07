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

//implementing merge sort algorithm
void merge(int arr[], int low, int mid, int high){
	int n1 = mid-low+1;
	int n2 = high - mid;
	int a[n1], b[n2];
	for (int i = 0; i<n1; i++)
		a[i] = arr[low+i];
	for (int i = 0; i<n1; i++)
		b[i] = arr[mid+1+i];
	int i,j,k;
	for (i=0, j = 0, k = low;i<n1 && j <n2; k++)	{
		if (a[i]<b[j]){
			arr[k]=a[i++];
		}
		else
			arr[k]=b[j++];
	}
	while(i<n1)
		arr[k++] = a[i++];
	while(j<n2)
		arr[k++] = b[j++];	
}
void mergeSort(int a[], int low, int high){
	if (low<high){
		int mid = (low+high)/2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
		merge(a,low, mid, high);
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
	mergeSort(arr, 0,size-1);
	printArray(arr, size);
	return 0;
}