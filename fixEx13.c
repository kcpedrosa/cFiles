#include <stdio.h>
/*
This program will check if, given the sides, a triangle can be
formed or not
It will also tell the classification taking the angles into account
*/


int main(void)
{
    int side1, side2, side3;
    int triangulator(int);

    
    printf("Enter first side of the triangle: \n");
    scanf("%i", &side1);
    printf("Enter second side of the triangle: \n");
    scanf("%i", &side2);
    printf("Enter third side of the triangle: \n");
    scanf("%i", &side3);

    triangulator(side1, side2, side3);





    return 0;
}

int triangulator(int side1, int side2, int side3){
    if((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1))
    {
        printf("OK, Triangle can be formed");
        /*side1 will be our hypotenuse*/
    if(side1*side1 == (side2*side2)+(side3*side3))
    {
        printf("The triangle given is RETANGULO");
    } 
    else if (side1*side1 > (side2*side2)+(side3*side3))
    {
        printf("The triangle given is OBTUSANGULO");
    }  else
    {
        printf("The triangle given is ACUTANGULO");
    } ;
    }
    else
    {
        printf("Triangle CANT be formed");
    }
    
    return 0;
}