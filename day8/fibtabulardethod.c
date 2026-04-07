//Program to find nth term of fibonacci series using recursive solution
#include <stdio.h>
//tabular
int fib(int n){
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i<=n; i++)
		dp[i] = dp[i-1] + dp[i-2];
	return dp[n];
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", fib(n));	
	return 0;
}