#include<stdio.h>
void main(){
	int control, sumOfSq, sqOfSum, difference;
	/*This program will calculate 
	the difference between the sum of the squares of the first 100 natural
	 numbers and the square of the sum of those numbers*/
	control=1;
	sumOfSq=0;
	sqOfSum=0;
	difference=0;
	for(control = 1; control<=100; control++){
		sumOfSq = sumOfSq + (control*control);
		/*obs: we could write += also*/
		sqOfSum = sqOfSum + control;
		
	}
	sqOfSum = sqOfSum*sqOfSum;
	difference = sqOfSum - sumOfSq;
	printf("the difference between the sum of the squares of the first 100 natural numbers and the square of the sum is:  \n");
	printf("%d \n", difference);
}