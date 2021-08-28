#include <stdio.h>
#include <stdlib.h>

//reading data

int main(void){
	FILE *file;
	file = fopen("string.txt", "r");
	//please return to name ''numero1.txt'' to read

	if(file == NULL){
		printf("File could not be opened/or does not exist \n");
		getchar();//just to persist the message in the screen waiting for input
		exit(0);//exit() kills the program
	}

	char frase[100];

	while(fgets(frase, 100, file) != NULL){
		//while there is something, loop continues
		printf("%s\n", frase);
	}
	//fgets() reads something till line break
	//if the user enters numbers they will be convert into string
	/*so if we take out while fgets will read only bread with cheese*/
	fclose(file);


	printf("\n");
	return 0;
}

