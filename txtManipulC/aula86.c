#include <stdio.h>
#include <stdlib.h>



int main(void){
	//obs fgets reads 5 minus 1
//that one is the null char \0
//try typping power or course or any word with 5 letters

	char x[50];
	fgets(x, 5, stdin);
	//standard input, it is the keyboard
	//r means read
	//stdin is a pointer, its type is file
	printf("%s\n", x);

	freopen("aula86.txt","r", stdin);
	//in that case stdin will point to the file
//and we will read what is inside
	 fgets(x, 15, stdin);
//will read 15 char minus 1, just to rmmmbr
	 printf("%s\n", x);


	return 0;
}
