/* 
This code will count as follows:
( equals to add a unit
) equals to subtract a unit
the result will combine ( ) and a number will be returned
example ( ) equals to zero
 */


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, counter;
    char amount[100];

    printf("Enter the parentheses: ");
    scanf("%s", amount);

for(x=0; x<100; x++)
    {
        if(amount[x] == '(' ){
            counter += 1;
        }
        else if(amount[x] == ')' ){
            counter -= 1;
        }
    }
    printf("Parentheses counter => Result: %i\n", counter);

    return 0;
}