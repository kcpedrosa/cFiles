#include <stdio.h>
#include <stdlib.h>

//reading data

int main(void){
	FILE *file;
	file = fopen("string.txt", "a");
	//a means append [more info]
	/*it will insert info in the txt file
	*/

	if(file == NULL){
		printf("File could not be opened/or does not exist \n");
		getchar();//just to persist the message in the screen waiting for input
		exit(0);//exit() kills the program
	}

	fprintf(file, "Very First line\n"); //writes first line in the txt file

	char frase[] = "Second line\n";
	fputs(frase, file);//insert the text ''second line''

	char caractere = '3';
	//for some reason I am not able to insert \n alongside 3
	fputc(caractere, file);//this func inserts one character


	printf("\n");
	return 0;
}

