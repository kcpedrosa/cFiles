#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//this is a statistical function, see bellow for explanation
float prob_density(float variable, float sigma, float average);

int main (void){
float i=0; 
float j=0;
float k=0;
float result;

srand(time(NULL));

i=rand()%10;
j=rand()%10;
k=rand()%10;

//next line is for debugging
printf("The random numbers are: \n");
printf("%f %f %f \n", i, j, k);

result = prob_density(i,j,k);
printf("%f \n", result );



}

float prob_density(float variable, float sigma, float average){
	/*
	this function has the following form:
	f(x) is our output, the normal distribution
	that is to say
	f(x) = (1/(sigma*squareroot)) * euler
	the euler number is exponentiated by the values bellow
	which are ((variable - average)/sigma) ^ 2 )*(-0.5);
	*/
	float exponent = (((variable - average)/sigma)*((variable - average)/sigma))*(-0.5);
	float euler = pow(2.7182, exponent);
	float squareroot = sqrt(2* 3.14);
	float result = (1/(sigma*squareroot))*euler;

	return result;
}