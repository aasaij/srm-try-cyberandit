
#include <stdio.h>
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
    //implementing selection sort algorithm
void selectionSort(int arr[], int n){
    for (int i = 0; i<n; i++){
        int minIndex = i;
        for (int j = i+1; j<n; j++)
            if (arr[minIndex]>arr[j])
                minIndex = j;
        if (i!=minIndex)
            swap(arr+minIndex, arr+i);
    }
}
void printArray(int a[], int n){
    printf("\n[");
    for (int i = 0; i<n-1; printf("%d,", a[i++]));
    printf("%d]", a[n-1]);
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    // for (int i = 0; i<n; i++)
    //     scanf("%d", &arr[i]);
    for (int i =0; i<n; scanf("%d", arr+i++));
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
