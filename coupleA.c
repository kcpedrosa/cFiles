#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(void){
char pessoa[5][20] = {0};
int i=0; 
int j=0;
int k=0;


srand(time(NULL));

printf("Insert the name of 5 persons: \n" );

for(k=0; k<5; k++){
	scanf("%[^\n]s", pessoa[k]);
}

while(i==j){
	i=rand()%5;
	j=rand()%5;
}
printf("\n %s likes %s \n", pessoa[i], pessoa[j] );
return 0;
}