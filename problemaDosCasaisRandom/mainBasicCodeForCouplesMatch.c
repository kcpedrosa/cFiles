
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates and prints 'count' random


int main()
{

    int lower = 0, upper = 2, count = 1;
  
    // Use current time as 
    // seed for random generator
    srand(time(0));
  
    //printRandoms(lower, upper, count);

    int i;
    //int r = num;
  
    // Direct initialization of 2-D char array
    char array[][20] = { "Ana", "John", "Zé" };
  
    // print the words
    for (i = 0; i < 3; i++){
        
        int num = (rand() %
           (upper - lower + 1)) + lower;
        printf("%d \n", num);
        
        printf("%s\n", array[num]);
        printf("Likes \n");
        printf("%s\n", array[num]);//it will print Ana likes Ana etc
    };
  
    return 0;
}