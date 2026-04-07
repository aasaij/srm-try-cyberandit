//Program to find nth term of fibonacci series using recursive solution
#include <stdio.h>
#include <limits.h>
//Memoization
int x;
int fib(int dp[], int n){
	x++;
	if(n<=1) // base case
		return n;
	if (dp[n]!=INT_MIN)
		return dp[n];
	return dp[n] = fib(dp, n-1) + fib(dp, n-2);
}

int main(){
	int n;
	scanf("%d", &n);
	int dp[n+1];
	for (int i = 0; i<=n; dp[i++]=INT_MIN);
	printf("%d", fib(dp,n));
	printf("\n%d", x);
	return 0;
}