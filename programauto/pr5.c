#include <stdio.h>
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
   printf("First name: %s Second name:  %s Third name: %s", str, str2, str3);
  
   return 0;
}