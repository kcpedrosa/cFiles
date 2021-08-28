#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int vaquinha_a(int a, int b, int c);
int vaquinhab(int a, int b, int c);

/*this is our final function
we will prove that our function works properly by estatistic 
Said in other words:
We will create a main function main() which will randomly sort the three of values ​​(a, b, c) and will call 
both vaquinha_a() and vaquinha_b() and compare the results (won or not).
You will perform 100,000 (one hundred thousand) experiments 
(in a loop in the main function) and print the results statistics after completing the simulation:
* Total: 100,000 iterations
* Functions A and B returned the same value in: X experiments
* Functions A and B returned different in: Y experiments*/
int main(void)
{
    
    int a, b, c;
    int j, x, y; 
    int vacaa, vacab;

    x=0;
    y=0;
    srand(time(NULL)); 

    for(j=1; j<=100000; j++)
    {
        a = 1 + rand() % 6; 
        b = rand() % 101; 
        c = -40 + rand() % 51; 

        vacaa= vaquinha_a(a, b, c);
        vacab= vaquinhab(a, b, c);


        if(vacaa==vacab)
            x++;
        if(vacaa!=vacab)
            y++;
    }
    j--;

    printf("Total: %i iterations \n", j);
    printf("Functions A and B returned the same value in: %i cases \n", x);
    printf("Functions A and B returned the same value in: %i cases \n", y);

    return 0;
}

int vaquinha_a(int a, int b, int c)
{
    if(a <= 6 && a > 4)
        if(b < 40)
            if(b < c)
                return 1;
            else
                return 0;
        else
           if(c >= a)
              return 1;
          else
             return 0;
    else
        if(a == 6)
            return 1;
        else
            if(a == 4)
                if(c < b)
                    return 1;
                else
                    return 0;
            else
                return 0;
}


int vaquinhab(int a, int b, int c)
{
    if((4<a && a<=6 && b<40 && b<c) || (4<a && a<=6 && b>=40 && c>=a) || (a==4 && c<b))  /* modify this line only! */
         return 1;
    else
         return 0;
}