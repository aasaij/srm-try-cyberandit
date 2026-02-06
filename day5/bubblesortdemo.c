//Program to implement bubble sort algorithm
#include <stdio.h>
void swap(int *x, int *y){
	*x = *x + *y - (*y=*x);
}
void bubbleSort(int arr[], int n){
	for (int i = 1; i<=n-1; i++){
		for (int j = 0; j<n-i; j++)
			if (arr[j]>arr[j+1])
//				swap(arr+j, arr+j+1);
				arr[j] = arr[j]+arr[j+1]- (arr[j+1]=arr[j]);
	}
}
void printArray(int arr[], int n){
	printf("\n[");
	for (int i = 00; i<n-1;i++)
		printf("%d,", arr[i]);
	printf("%d]", arr[n-1]);
}
int main(){
	int arr[] = {10, 7, 9, 11, 17, 21, 4};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, arrSize);
	printArray(arr, arrSize);
	return 0;
}