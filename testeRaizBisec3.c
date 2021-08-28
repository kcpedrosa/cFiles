#include <stdio.h> //printf, scanf
#include <stdlib.h> //EXIT_SUCCESS


#define ERROMAX 0.001

/*-------------------------------------------------------------------------------------------*/
//prototipos
//recebe um valor n e retorna sua raiz quadrada
float raiz(float n);
int float_igual(float a, float b);
/*-------------------------------------------------------------------------------------------*/
/* Funcao principal
       - Nao recebe valores
       - retorna sempre sucesso
 */

int main(void)
{
    float n, /* valor de entrada a ser calculado */
          r; /*valor de raiz de n */

    printf("Digite o valor para ser calculado.\n?: ");
    scanf("%f", &n);

    r=raiz(n);
    if(r<0.0)
    {

        printf("erro: nao calculo numeros negativos!!\n");
    }
	else if(0 < r && r < 1)
    {
		printf("Nao calculo numeros entre 0 e 1!!\n");
    }
	else
    {
		printf("O valor da raiz de (%.2f) eh: %.2f\n", n, r);
    }
	return EXIT_SUCCESS;
}

/* ------------------------------------------------------------------------------------------*/
/* recebe um valor n e retorna sua raiz quadrada */
float raiz(float n)
{
    float r, a; /* Valor aproximado da raiz */
    float m, b; /* valor aproximado de n */

    if(n<0.0)
        return -1.0; /*Erro, nao calculo valores menores que 0 */
    if(n<1.0)
        return -2.0; /* Erro nao calculo valores entre 0 e 1 */

    a=1.0;
    b=n;

    while(1)
    {
    r=(a+b)/2.0; /* Estimativa inicial */

    m=r*r;
    if(float_igual(m, n))
        return r;
    if(m<n)
        /* Raiz esta no intervalo [r,b] */
        a=r;
    else
        /* Raiz esta no intervalo [a,r] */
        b=r;
    }

    return r;
}

/* -----------------------------------------------------------------------------------------*/
// Recebe dois valores float e compara pela igualdade
int float_igual(float a, float b)
{
    if(a-ERROMAX < b && a+ERROMAX > b)
        return 1;
    return 0;
}
