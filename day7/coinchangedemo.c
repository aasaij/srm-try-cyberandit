#include <stdio.h>
#include <stdlib.h>
//coin change problem using greedy
int compare (const void *x, const void *y){
	return *(int*)y - *(int*)x;
}
int main(){
	int amt, numDenoms, totalCoins=0;
	scanf("%d", &amt);
	scanf("%d", &numDenoms);
	int denoms[numDenoms];
	for (int i = 0; i<numDenoms; scanf("%d", &denoms[i++]));
	qsort(denoms, numDenoms, sizeof(denoms[0]), compare);
	for (int i = 0; i<numDenoms && amt!=0;i++){
		if (amt < denoms[i]) continue;
		int curCoins = amt / denoms[i];
		totalCoins += curCoins;
		amt -= curCoins * denoms[i];
	}
	printf("%d", amt==0?totalCoins:-1);
	return 0;
}