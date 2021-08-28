#include <stdio.h>
#include <stdlib.h>



int main(void){

	char x[100];
	//FILE *file = fopen("aula87um.txt", "r");

/*
	x[0] = fgetc(stdin);
	//getc() would return the same of fgetc()
//getc() was origin a macro
	//r means read
	//x is our vetor
	/*if you type more, the keyboard will carry it
to next function
*/
/*
	printf("%c\n", x[0]);
	//obs '\n' means enter
*/
	printf("Enter a string/ max 99 characters \n");


	int i= 0;
	while((x[i] = fgetc(stdin)) != '\n' ){
		++i;
	}
	//manually add null character
	//try to comment next line
	x[i] = '\0'; //this \0 is inserted over the \n
	//it avoids the 'garbage' as the prof said
	//try to use bellow instead of above
	//x[++i] = '\0';
	//cursor will be positioned a line bellow 

	printf("%s\n", x);

	return 0;
}
