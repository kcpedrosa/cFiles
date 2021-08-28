#include <stdio.h>
int main() {
    /*
    What is the largest prime factor of the number 600851475143 ?
    Prime factor is a number that results from the division of a
    number in smaller numbers, the prime factors
    Example 124 can be written as 2 x 2 x 31, 31 is the largest prime factor
    */

   long int n;
   n=600851475143 ;
   long long int div=2, ans = 0, maxfactor;
   while(n!=0) {
      if(n % div !=0)
         div = div + 1;
      else {
         maxfactor = n;
         n = n / div;
         if(n == 1) {
            printf("%d is the largest prime factor of the number entered",maxfactor);
            ans = 1;
            break;
         }
      }
   }
   return 0;
}
