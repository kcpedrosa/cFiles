#include <stdio.h>
#include <stdlib.h>

//reading data

int main(void){
	FILE *file;
	file = fopen("numeros.txt", "r");
	//please return to name ''numero1.txt'' to read

	if(file == NULL){
		printf("File could not be opened/or does not exist");
		return 0;
	}

	int x, y, z;
	fscanf(file, "%i %i %i ", &x, &y, &z);
	printf("%i %i %i \n", x, y, z);
	fclose(file);

	return 0;
}

