#include <stdio.h>
int
main ()
{
  /*this program will calculate the
  largest prime factor of the number 600851475143
   
                       */

  long int n;
  n = 600851475143;
  long long int div = 2, ans = 0, maxfactor;
  while (n != 0)
    {
      if (n % div != 0)
  div = div + 1;
      else
  {
    maxfactor = n;
    n = n / div;
    if (n == 1)
      {
        printf
    ("%d is the largest prime factor of the number entered \n",
     maxfactor);
        ans = 1;
        break;
      }
  }
    }
  return 0;
}
