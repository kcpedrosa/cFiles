#include <stdio.h>
/*
This program will check if, given the sides, a triangle can be
formed or not
It will also tell the classification taking the angles into account
*/
int main(void)
{
    int side1, side2, side3;

    
    printf("Enter first side of the triangle: \n");
    scanf("%d", &side1);
    printf("Enter second side of the triangle: \n");
    scanf("%d", &side2);
    printf("Enter third side of the triangle: \n");
    scanf("%d", &side3);


    if((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1))
    {
        printf("OK, Triangle can be formed \n");
        /*side1 will be our hypotenuse*/
        if(side1*side1 == (side2*side2)+(side3*side3))
    {
        printf("The triangle given is RETANGULO \n");
    } 
    else if (side1*side1 > (side2*side2)+(side3*side3))
    {
        printf("The triangle given is OBTUSANGULO \n");
    }  else
    {
        printf("The triangle given is ACUTANGULO \n");
    } ;
    }
    else
    {
        printf("Triangle CANT be formed \n");
    }
    
    


    return 0;
}