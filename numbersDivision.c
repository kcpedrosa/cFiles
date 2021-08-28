#include <stdio.h>
int main() {
	float x, y;
	float resultOfDivision;
	printf("Division of numbers: use dot for float numbers, not comma \n");
    printf("Type two numbers : \n");
	printf("\n x: ");
    scanf("%f", &x);
    printf("\n y: ");
    scanf("%f", &y);


    resultOfDivision = x/y;
    printf("%.2f \n", resultOfDivision);

  return 0;
}
