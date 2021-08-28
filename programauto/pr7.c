#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*this program will select ten people
then it will make a couple match in a random manner
*/

int main(void)
{
    char p[10][20];
    int i, k, w;

    printf("Match maker: type your name to find your partner:\n");
    for(i=0; i<10; i++)
    {
        printf("Enter name %i:", i+1);
        scanf("%s", p[i]);
    }

    srand(time(NULL));

    k = rand() % 10;
    w= rand() % 10;

//this is to avoid a match with yourself
    while(k==w)
    {
        w= rand() % 10;
    }

    printf("%s likes %s\n", p[k], p[w]);

    return 0;
}