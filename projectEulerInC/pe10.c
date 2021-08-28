#include <stdio.h>
#include <math.h>
#define n 2000001
/*that define is bcs we will try to find numbers bellow 2 million*/

int main ()
{
  /*This program will calculate the sum of all the primes below two million */
	/*Concept used: sieve of Eratosthenes*/
  long long a, b, sum;
  static int primes[n];
  a = b = sum = 0;

  for (a = 0; a <= n; a++)
    {
      primes[a] = 1;

    }
  for (a = 2; a <= sqrt (n); a++)
  	//zero and one are not prime so we can start with 2
  	//remember, 2 is prime
    {
      if (primes[a] == 1)
	{
	  for (b = a; a * b <= n; b++)
	    {
	      primes[a * b] = 0;
	    }
	}
    }
  for (a = 2; a <= n; a++)
    {
      if (primes[a] == 1)
	{
	  sum = sum + a;
	}
    }
  printf ("The sum is: %lld \n", sum);

}
