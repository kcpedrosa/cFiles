#include <stdio.h>
#include <stdlib.h>

int main(void){

	char y[5];
	char x[5];

//gets do not limits the number of chars inputed
/*
It can open your PC to external threats
*/
	gets(x);//throws a b char in your screen
//safer function is gets_s()

	printf("%s\n", x);

	return 0;
}
