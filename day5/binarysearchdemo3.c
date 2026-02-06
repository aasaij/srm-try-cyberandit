//Program to implement binary search using bsearch()
#include <stdio.h>
#include <stdlib.h>
int compare(const void* x, const void *y){
	return *(int*)x - *(int*)y;
}
int main(){
	int arr[] = {1,2,3,4,5,6,7,11,12,19};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	int search;
	scanf("%d", &search);
	int *index = (int*)bsearch(&search, arr, arrSize, sizeof(int), compare);
	if(index != NULL)
		printf("Found @ %d\n", index-arr);
	else
		printf("Not found!");
	return 0;
}