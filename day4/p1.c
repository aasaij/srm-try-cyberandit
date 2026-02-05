#include <stdio.h>
//puzzle 1
int main(){
	char x = 250;
	int y;
	printf("%d", x);
	y = x + !x + ~x + ++x;
//	printf("%d", x);
//	printf("%d", 9943115155);
	return 0;
}

//	0000 0000
//x	1111 1010