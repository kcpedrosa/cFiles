#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//this program will create a 3x3 matrix with random numbers
//and will return its determinant
int main (void)
{
	int matrix[3][3];
	int determinant;
	int i, j;
	int count = 3;
	srand(time(NULL));
	for ( i = 0; i < count; i++)
	 {
	 	for ( j = 0; j < count; j++)
	 	{
	 		matrix[i][j] = rand()%5;
	 	}
	 }

	 determinant=((matrix[0][0]*matrix[1][1]*matrix[2][2])+
	 	(matrix[0][1]*matrix[1][2]*matrix[2][0])+
	 	(matrix[0][2]* matrix[1][0]*matrix[2][1])
	 	)-
	 ((matrix[0][2]*matrix[1][1]*matrix[2][0])+
	 	(matrix[0][0]*matrix[1][2]*matrix[2][1])+
	 	(matrix[0][1]*matrix[1][0]*matrix[2][2]));

	 

	 for(i=0;i<count;i++)
	 {
	   for(j=0;j<count ;j++)
	   {
	     printf("matrix [%i] [%i] = %i \n",i, j, matrix[i][j]);
	    }
	 }
	 
	 printf("The determinant is : %i \n", determinant);

	return 0;
}