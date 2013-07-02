/*

  The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

  1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

  Let us list the factors of the first seven triangle numbers:

  1: 1
  3: 1,3
  6: 1,2,3,6
  10: 1,2,5,10
  15: 1,3,5,15
  21: 1,3,7,21
  28: 1,2,4,7,14,28

  We can see that 28 is the first triangle number to have over five divisors.

  What is the value of the first triangle number to have over five hundred divisors?

*/

#include <stdio.h>
#include <math.h>
#include "genprimes.h"
#include "findfactors.h"

int main()
{
  int input;
  int maxnumfactors = 0;
  int trinum = 0;
  int i, j;
  int *primes; 
  primes = genprimes();

  printf("\nPlease input a maximum: \n");
  scanf("%d", &input);
  
  // find triangle numbers and store number of divisors until input reached
  for(i=1;maxnumfactors<input;i++){   
    int thisnumfactors;
    trinum+=i;
    thisnumfactors=findfactors(trinum,primes);
    printf("%d %d\n",trinum,thisnumfactors);
    if(thisnumfactors>maxnumfactors){
      maxnumfactors=thisnumfactors;
    }
  }
  printf("\nMax Factor %d Triangle Number %d\n", maxnumfactors, trinum);
  return 0;
}
