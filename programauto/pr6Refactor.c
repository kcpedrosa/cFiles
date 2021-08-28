#include <stdio.h>
#include <stdlib.h>


void printnames(char w[1][3][30]);

/*
we will create a function that will read 3 names
and will print them
this func could be set to read x names also
in that case create int counter in the place of  j = 3
and adjust the matrix
*/
int main(void)
{
    char Names [1][3][30] = {{{'0'}}};

  
    printf("Enter the names to be printed : \n");
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%[^\n]", Names [i][j]);
        }
    }

    
    printf("Names that were entered are : \n");
    printnames(Names);

    return 0;
}


void printnames(char w[1][3][30])
{
    for(int i=0; i<1; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<30; k++)
            {
                printf("%c", w[i][j][k]);
            }
            printf("\n");
        }
    }
}
