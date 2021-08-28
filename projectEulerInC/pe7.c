#include <stdio.h>

int
main (void)
{
  /*this program will find the 10 001st prime number*/
  long count, currentNumber, primeCount;

  primeCount = 1;

  /*plus 2 in order to pass even numbers*/
  for (currentNumber = 3; primeCount != 10001; currentNumber = currentNumber + 2){
      for (count = 3; count < currentNumber; count = count + 2)	{
	  if (currentNumber % count == 0)
	    break;
	}
      if (count == currentNumber)
	primeCount++;
    //printf("%li\n", primeCount); //uncmnt this line to see that counting 
    }/*will keep adding until it hits the 10001*/

  printf ("The 10001st prime number is: %li", count);
  return 0;
}