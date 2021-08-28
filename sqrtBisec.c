#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
This code will find the square root of a float number
through the bissection method
 
*/


int main(){
	float num = 0;
	float y = 0;
	float x = 0;
	float sqrt = 0;
	printf("Enter the number to find its square roots: \n");
	scanf("%f", &y);
	num = y;

	while((abs((sqrt*sqrt) - abs(num)) > 0.001) && (sqrt <= y)){
		sqrt = (x + y) / 2.0;

    if((sqrt*sqrt) < num){
        x = sqrt;
    }
    else{
        y = sqrt;
    }
	}
	printf("The square root is :\n");
	printf("%f\n", sqrt);
}