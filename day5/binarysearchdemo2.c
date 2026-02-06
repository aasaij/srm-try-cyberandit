//Program to implement binary search algorithm using RECURSION
#include <stdio.h>
int binarySearch(int low, int high, int arr[], int searchElement){
	if (low<=high){
		int midIndex = (low+high)/2;
		if (arr[midIndex]==searchElement)
			return midIndex;
		else if (arr[midIndex]<searchElement)
			return binarySearch(midIndex+1, high, arr, searchElement);
		else
			return binarySearch(low, midIndex-1, arr, searchElement);
	}
	return -1;

}
int main(){
	int arr[] = {1,2,3,4,5,6,7,11,12,19};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	int search;
	scanf("%d", &search);
	int index = binarySearch(0, arrSize-1,arr, search);
	if(index != -1)
		printf("Found @ %d\n", index);
	else
		printf("Not found!");
	return 0;
}