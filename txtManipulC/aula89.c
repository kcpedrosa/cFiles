#include <stdio.h>
#include <stdlib.h>



int main(void){

	char x[100];
	FILE *file = fopen("aula89.txt", "r");

	//EOF means end of file
//it will stop when it hits EOF
	int i= 0;
	//it will read from file in fgetc
	while((x[i] = fgetc(file)) != EOF ){
		++i;
	}

	x[i] = '\0';

	printf("%s\n", x);

	return 0;
}
