#include <stdio.h>
//class 81 de aluno para aluno c

int main(void){
	/*when you do not specify the path, the txt file is created
	where the source code is
	obs: 1;Stephen Hawking;A Brief History of Time: From the Big-Bang to Black Holes;Bantam;London;1988;1;9780553380163;2
2;John Craig Wheeler;Cosmic Catastrophes: Exploding Stars, Black Holes, and Mapping the Universe;Cambridge;New York;2007;;;1
3;Chris Impey;Einstein’s Monsters: the Life and Times of Black Holes;Deutch Bib;Berlin;2019;;;1
	this is the format of books intended to be saved
	just a reminder
*/
	FILE *file;
	file = fopen("teste1.txt", "w");

	fprintf(file, "LOTR.");
	fclose(file);

	return 0;
}