#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*this is our function*/
void vaquinhab(int a, int b, int c);

/*the objective here is still own a cow or not
but we will simplify our funtion vaquinhab()
only one if-else allowed*/
int main(void)
{
    
    int a,b,c;
    srand(time(NULL)); 

    a = 1 + rand() % 6;
    b = rand() % 101;
    c = -40 + rand() % 51;

    printf("Slice and dice roll: %i\n Percentage: %i\n Temperature: %i\n", a, b, c);
    vaquinhab(a, b, c);

    return 0;
}


void vaquinhab(int a, int b, int c)
{
    printf("(funcao B): Voce... ");
    if((4<a && a<=6 && b<40 && b<c) || (4<a && a<=6 && b>=40 && c>=a) || (a==4 && c<b))  /* modificar apenas essa linha! */
        printf("ganhou a vaquinha!\n");
    else
        printf("nao ganhou a vaquinha!\n");
}