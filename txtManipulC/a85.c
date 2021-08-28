#include <stdio.h>
#include <stdlib.h>



int main(void){
	void copyContent(FILE *file1, FILE *file2);

	FILE *file1;
	file1 = fopen("arquivo1.txt", "r");
	//r means read


	if(file1 == NULL){
//this is a kind of block try catch, it raise error msg
		printf("File could not be opened/or does not exist \n");
		//getchar();//just to persist the message in the screen waiting for input
		//exit(0);//exit() kills the program
		return 1;
	}

	FILE *file2 = fopen("arquivo2.txt","w");
//changing to a instead of w will cause info appending
//will not overwritte text
//w is for writte, but we will copy content in that case
	copyContent(file1, file2);

	fclose(file1);
	fclose(file2);

	return 0;
}
void copyContent(FILE *file1, FILE *file2){
	char leitor[10000];
//remmbr: fgets() reads a string in a file
	while(fgets(leitor, 10000, file1) != NULL){
		fputs(leitor, file2);
	}
}
