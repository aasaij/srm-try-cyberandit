//Program to implement fractional knapsack
#include <stdio.h>
#include <stdlib.h>
typedef struct Product{
	double profit;
	double weight;
	double ratio;
}product;
int compare(const void *x, const void *y){
	return ((product*)y)->ratio - ((product*)x)->ratio;
}
int main(){
	int bagSize;
	int numItems;
	double profit = 0;
	scanf("%d", &bagSize);
	scanf("%d", &numItems);	
	product products[numItems];
	for(int i = 0; i<numItems; i++){
		scanf("%lf %lf",&products[i].profit,&products[i].weight);
		products[i].ratio = products[i].profit / products[i].weight;
	}
	qsort(products,numItems,sizeof(products[0]), compare);
	for(int i = 0; i<numItems && bagSize!=0; i++){
		if (products[i].weight<=bagSize){
			profit += products[i].profit;
			bagSize -= products[i].weight;
		}
		else{
			profit += products[i].ratio * bagSize;
			bagSize = 0;
		}
	}
	printf("%.2lf", profit);
	return 0;
}