#include <stdio.h>

int
main ()
{

  /*We will find the largest palindrome made from the product of two 3-digit numbers*/
  int x, y;
  int product, reverseProduct, reverse, max;

  max = 0;
  for (x = 100; x < 1000; x++)
    {       /*that is because the numbers range from 100 to 999, which is
           smaller than 1000 */
      for (y = 100; y < 1000; y++)
  {

    product = x * y;
    reverseProduct = product;
    reverse = 0;

    while (reverseProduct > 0)
      {
        reverse = reverse * 10 + reverseProduct % 10; /*the modulus will help take the last number of the target number */
        reverseProduct = reverseProduct / 10;



      }
    if (reverse == product) /*then the number is a palindrome */
      {
        if (product > max)
    {
      max = product;
    }
      }

  }
    }
  printf("This code will find the largest palindrome made from the product of two 3-digit numbers \n");
  printf("Largest palindrome is:  %d \n", max);

}