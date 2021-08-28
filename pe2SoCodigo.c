#include <stdio.h>
#include <stdlib.h>

int main()
{
        /*By considering the terms in the Fibonacci sequence whose values do not exceed four million,
         *     find the sum of the even-valued terms*/
    int i=1,j=1,sum=0;
        while(i<4000000)
                {
                i=i+j;
                j=i-j;
                if(i%2==0)
                 sum+=i;
                                    }
        printf("Sum is: %d",sum);
        //returns 4613732
      }
