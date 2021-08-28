#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Find the sum of all the multiples of 3 or 5 below 1000
  int sum = 0;

  for (int x = 0; x < 1000; x++)
  {
    if (x % 5 == 0 || x % 3 == 0)
      sum += x;
  }

  printf("%d", sum);
}
