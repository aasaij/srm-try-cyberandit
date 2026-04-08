//Program to find the number of ways to climb the staircase
#include <stdio.h>
int countWays(int dp[], int n){
	if (n<=2)
		return n;
	if (dp[n]!=-1)
		return dp[n];
	return dp[n] = countWays(dp, n-1) + countWays(dp, n-2);
}
int main(){
	int n;	
	scanf("%d", &n);
	int dp[n+1];
	//initializing all array elements into -1
	for (int i = 0; i<=n; dp[i++]= -1);	
	printf("%d", countWays(dp, n));
	return 0;
}