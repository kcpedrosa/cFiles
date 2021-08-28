#include <stdio.h>
void main(){
	/*This program will do the following:
	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc
	*/
	int a, b, c, sum, product, aSquare, bSquare, cSquare;
	a = b = c = sum = product = aSquare = bSquare = cSquare = 0;
	sum = 1000;
	/*we will set the barrier to 1000 for the sum*/
	for (a = 1; a < (sum/3); a++)
	{
		for (b = 2; b <(sum/2); b++)
		{/*sum divided by 2 and 3 is to ensure that we do not brake the 1000 barrier*/
			c = sum - b - a;
			aSquare = a*a;
			bSquare = b*b;
			cSquare = c*c;
			if ((aSquare + bSquare) == cSquare)
			{
				/*the question says that there is just one pit triplet in 
				these conditions, so if it meets conditions, we found it*/
				printf("A B C are: %d %d %d \n", a, b, c);
				product = a * b * c;
				printf("The triplet is: %d \n", product);

				
			}
			
		}
	}
}











