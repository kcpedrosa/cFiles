#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*here we declare the function ''vaquinha_a()''*/
void vaquinha_a(int a, int b, int c);

/*the main program will tell if you own a cow
[that is the objective of this program]
based on 3 packs of random numbers*/
int main(void)
{
    /*the vars bellow will determine your fate*/
    int a, b, c;

    srand(time(NULL)); /*randomizer function*/
    a = 1 + rand() % 6;
    b = rand() % 101;
    c = -40 + rand() % 51;

    printf("O dado(a): %i\nA porcentagem(b): %i\nA temperatura(c): %i\n", a, b, c);
    vaquinha_a(a, b, c);

    return 0;
}

/*in that stage the function bellow will remain unaltered*/
void vaquinha_a(int a, int b, int c)
{
        printf("(funcao A): Voce... ");
        if(a <= 6 && a > 4)
            if(b < 40)
                if(b < c)
                    printf("ganhou a vaquinha!\n");
                else
                    printf("nao ganhou a vaquinha!\n");
            else
                if(c >= a)
                    printf("ganhou a vaquinha!\n");
                else
                    printf("nao ganhou a vaquinha!\n");
        else
            if(a == 6)
                printf("ganhou a vaquinha!\n");
            else
                if(a == 4)
                    if(c < b)
                        printf("ganhou a vaquinha!\n");
                    else
                        printf("nao ganhou a vaquinha!\n");
                else
                    printf("nao ganhou a vaquinha!\n");

}