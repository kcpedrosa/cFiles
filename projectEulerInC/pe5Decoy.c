#include <stdio.h>

void main(){
	/*
	this program will calculate
	the SMALLEST positive number that is evenly divisible by all of the numbers from 1 to 20
	that is to say, it must be divisible by all numbers from 1 to 20
	*/
	int x, y, smallest;
	x=1;
	y=1;
	smallest = 0;

	while(x>0){
		y=1;
		while((x % y == 0) && (y<=20)){
/*modulos guarantees that the number is evenly divisible*/
			if(y==20){
				smallest = x;
				break;
			}
			y++;
		}
		x++;
		if(smallest > 0){
			break;
		}
	}
	printf("The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is  %d \n",smallest);


}