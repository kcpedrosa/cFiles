#include <stdio.h>
int main() {    

    float number1, number2, sum;
    printf("This program will calculate the sum of 2 numbers(can be a float!) \n");
    printf("Enter the first number: \n");
    scanf("%f",&number1);
    printf("Enter the second number: \n");
    scanf("%f",&number2);

    
    sum = number1 + number2;      
    
    printf("%.3f + %.3f = %.3f \n", number1, number2, sum);
    return 0;
}