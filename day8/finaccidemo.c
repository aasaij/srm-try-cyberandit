//Program to find nth term of fibonacci series using recursive solution
#include <stdio.h>
int x;
int fib(int n){
	x++;
	if(n<=1) // base case
		return n;
	return fib(n-1)+fib(n-2);
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", fib(n));
	printf("\n%d", x);
	return 0;
}