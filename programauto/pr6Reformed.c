#include <stdio.h>
char letsprint(char c1, char c2, char c3)
{
     printf("First name: %s Second name:  %s Third name: %s", c1, c2, c3);

     
}

int main()
{
   printf("This program will read 3 names and print them! \n");
   char str[30];
   char str2[30];
   char str3[30];
   printf("Enter the first name: \n");
   scanf("%[^\n]%*c", str);
   printf("Enter the second name: \n");
   scanf("%[^\n]%*c", str2);
   printf("Enter the thrid name: \n");
   scanf("%[^\n]%*c", str3);

   letsprint(str, str2, str3);

   //https://beginnersbook.com/2014/01/c-functions-examples/
  


   
  
   return 0;
}