//Program to find minimum currencies - coin change using dynamic programming
#include <stdio.h>
#define MIN(x, y) (x>y?x:y)
//int min(int x, int y){
//	return x < y ? x : y;
//}
int minimumCoins(int amt, int d[], int n){
	int dp[n+1][amt+1];
	for (int c = 0; c<=amt; c++)
		dp[0][c] = 0;
	for (int r = 0; r<=n; r++)
		dp[r][0] = 0;
	for (int r = 1;r<=n; r++ ){
		for (int c = d[r-1];c<=amt; c++){
			
		}
	}
	
		
}
int main(){
	int amt, nDenoms;
	scanf("%d", &amt);
	scanf("%d", &nDenoms);
	int denoms[nDenoms];
	for (int i = 0; i<nDenoms; scanf("%d", denoms+i++));	
	printf("%d", minimumCoins(amt, denoms, nDenoms));
	return 0;
}