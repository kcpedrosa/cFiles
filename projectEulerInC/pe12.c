#include <stdio.h>
#include <math.h>

int
main ()
{
  /*this program will search for
     the value of the first triangle number to have over 
     five hundred divisors */
  int triangNum = 0;
  int natNum = 0;
  int divisors;
  int i;
  /*OBS The triangular number sequence is the 
     representation of numbers in the form of 
     equilateral triangle arranged in a series or sequence. */

  while (1)
    {
      natNum++;
      triangNum = triangNum + natNum;
      divisors = 0;

      for (i = 1; i < (int) floor (sqrt (triangNum)); i++)
	{
	  if (triangNum % i == 0)
	    divisors = divisors + 2;

	  /*searching for a perfect square */
	  if ((int) floor (sqrt (triangNum)) *
	      (int) floor (sqrt (triangNum)) == triangNum)
	    divisors--;

	}
      if (divisors > 500)
	break;
      /*that is because we are searching for over 500 divisors */
    }
  printf ("Triangle number with  %d  divisors is: %d \n", divisors,
	  triangNum);
}
