/* Metodo da bissecção para calcular a raiz quadrada
2021 (C) Maria Cecília Galvao Da Silva Jota*/
/*---------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

double raiz(double a);
/*----------------------------------------------------*/
//função principal que lê o número e imprime o resultado
int main(void) 
{
 double r, x1;

printf("\nQual a raiz que desejas calcular: ");
  scanf("%lf", &x1); 

if (x1 < 0.0 || x1 <=1)
{
  printf("nao calculamos esse numero");
}
else
printf("\nA raiz de %lf e igual a: %lf\n",x1, raiz(x1));
  return 0;
}
/*--------------------------------------------------*/
//função que recebe valor e calcula os intervalos para encontrar a raiz 

double raiz(double x1)
{
double fun1, fun2, xqua, b, a, n, n1, r, fun;

for(b=-x1/2; b < x1/2 ; b++)//iniciando primeiro intervalo
{
for(a=0; a < x1; a++)//segundo intervalo
{
  fun1= (b*b) - x1;//valor do primeiro intervalo
  fun2= (a*a) - x1;//valor do segundo intervalo
  if(fun1 * fun2 < 0)
  {
    n1= a;
    n= b;
  }
}
}
//loop para estimativas
do
{
r=((n+n1)/2);//ponto inicial de estimativas
xqua=(r*r);

if (xqua < x1)
n1 = r;
else
n = r;

fun=((xqua)-x1);

if(fun < 0) n1 = r;
else n = r;
}
while (fun != 0);

return r;
}