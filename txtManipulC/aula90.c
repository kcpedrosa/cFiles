#include <stdio.h>
#include <stdlib.h>



int main(void){

	char x[] = "very big hamburguer";
	FILE *file = fopen("aula89.txt", "w");

//fputc and putc do the same
/*
but the putc could be used as a macro
*/
	putc(x[1], stdout);//throws a b char in your screen
	int i = 0;
	while(i<sizeof(x)){
        putc(x[i], stdout);
        ++i;
	}
	putc(x[0], file);
	int i2 = 0;
	while(i2<sizeof(x)){
        putc(x[i2], file);
        ++i2;
	}
	int i3 = 0;
	while(x[i] != '\0'){
        fputc(x[i3], file);
        ++i3;
	}/*the \0 is the null char that 
	is present in the end of the line*/





	return 0;
}
