/* 
Prime numbers always intrigued humanity
in this code, we will reveal if a number is prime or not 
enter a number to receive a answer on that regard
*/
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int x, y, counter;

    printf("Enter a number to know if it is PRIME or not \n");
    printf("Enter a number: \n");
    scanf("%i", &x);

    counter = 0;
    for(y=1; y <= x ; y++)
    {
        if(x%y == 0)
            counter += 1;
    }

    if(counter==2){
        printf("The number %i is PRIME.\n", x);
    }

    else{
        printf("The number %i is not PRIME \n", x);
    }

    return 0;
}