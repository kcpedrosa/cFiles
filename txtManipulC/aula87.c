#include <stdio.h>
#include <stdlib.h>



int main(void){
	//obs fgets reads 5 minus 1
//that one is the null char \0
//try typping power or course or any word with 5 letters

	char x[100];
	FILE *file = fopen("aula87um.txt", "r");


	fgets(x, 100, file);
	//r means read
	//x is our vetor
	
	printf("%s\n", x);
//ATTENTION
//we will redirect the *file to pointo to another file
	freopen("aula87dois.txt","r", file);
	
	 fgets(x, 100, file);
//will read 15 char minus 1, just to rmmmbr
	 printf("%s\n", x);


	return 0;
}
