#include <stdio.h>
#include <stdlib.h>

int main(void){
   /* printf("Type a char \n");
	char y[10];
	y[0]=getchar();

	printf("%c\n", y[0] );
*/

//\n is enter, a line break
	char x[10];
	int i = 0;
//x[9] is the last because the count begins on x[0]
	while((x[i]=getchar()) != '\n' && i < 8){
		++i;
	}
	/*this will force the i to be 8, and we will add 1
so we can add in the last posit the null char \0 that indicat
end of line
*/
	x[++i] = '\0';

	printf("%s\n", x);






	return 0;
}
