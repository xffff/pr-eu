/*
n is the given number...
where each p is a prime number
n=p1^e1*p2^e2* ... *pk^ek
number of factors of n is
(e1+1)*(e2+1)* ... *(ek+1)
 */

#include <stdio.h>
#include "findfactors.h"

int findfactors(int n, int *primes)
{
  int initial_n = n;
  int factors = 1;
  int i;

  for(i=0;primes[i]*primes[i]<=n;i++){
    int power=0;
    while(initial_n%primes[i]==0){
      initial_n/=primes[i];
      power++;
    }
    factors*=power+1;
  }
  if(initial_n>1)
    factors*=2;
  return factors;
}
