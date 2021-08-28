#include<stdio.h>
#include<stdlib.h>

char Fautor(char autor[200]);
int Fano(int ano[5]);
char Ftitulo(char titulo[200]);
int Feditora(int editora[5]);
char Flocal(char local[200]);

int main()
{
   char telas = ' ';
   char titulo[200];
   char autor[200];
   int ano[10];
   char local[200];
   int editora[5];

   printf("Você está apenas na tela de inicio!\nDigite o caractere equivalente a tela a qual deseja entrar...\nTela 'a' = adicionar livro\nTela 'b' = consulta de livro\nTela 'c' = retificar livro\nTela 'd' = deletar livro\nTela 'e' = sobre\n:");
   scanf("%c", &telas);

           if(telas == 'a')
           {
               printf("Voce esta na tela A para adicionar um livro!\n");
               Fautor(autor);
               Fano(ano);
               Flocal(local);
               Ftitulo(titulo);
               Feditora(editora);
           }
           if(telas == 'b')
           {
               printf("Voce esta na tela B para consultar um livro!\n");
               Fautor(autor);
               Ftitulo(titulo);
               Flocal(local);
           }
           if(telas == 'c')
           {
               printf("Voce esta na tela C para reitificar um livro!\n");
               Fautor(autor);
               Flocal(local);
               Ftitulo(titulo);
           }
           if(telas == 'd')
           {
               printf("Voce esta na tela D para deletar um livro!\n");
               Flocal(local);
               Fautor(autor);
               Ftitulo(titulo);
           }
           if(telas == 'e')
           {
               printf("Voce esta na tela E!\nAqui voce recebe as informações dos autores do projeto...\n");
           }
       return 0;
}
char Fautor(char autor[200])
{
    printf("Digite os dados do livro para realizar a...\nAutor:");
    scanf("%s", autor);

    printf("o nome do autor do livro eh %s!\n", autor);
    return 0;
}
int Fano(int ano[10])
{
    printf("Digite o ano do livro: \n");
    scanf("%i", &ano);

    printf("o livro eh do ano %i!\n", ano);
    return 0;
}
char Ftitulo(char titulo[200])
{
    printf("Digite o titulo: \n");
    scanf("%s", titulo);

    printf("%s\n", titulo);
    return 0;
}
int Feditora(int editora[5])
{
    printf("Digite o numero da editora: \n");
    scanf("%i", &editora);

    printf("%i\n", editora);
    return 0;
}
char Flocal(char local[200])
{
    printf("Digite o local: \n");
    scanf("%s", local);

    printf("%s\n", local);
    return 0;
}