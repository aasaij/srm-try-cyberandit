//Program to implement binary search algorithm using iteration
#include <stdio.h>
int binarySearch(int arr[], int n, int searchElement){
	int low = 0;
	int high = n-1;
	while(low <= high){
		int midIndex = (low + high) / 2;
		if (arr[midIndex]==searchElement)
			return midIndex;
		else if (arr[midIndex]>searchElement)
			high = midIndex - 1;
		else
			low = midIndex + 1;
	}
	return -1;
}
int main(){
	int arr[] = {1,2,3,4,5,6,7,11,12,19};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	int search;
	scanf("%d", &search);
	int index = binarySearch(arr, arrSize, search);
	if(index != -1)
		printf("Found @ %d\n", index);
	else
		printf("Not found!");
	return 0;
}