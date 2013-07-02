/*
 *  genprimes.c
 *  euler
 *
 *  Created by mike on 19/03/2013.
 *  Copyright 2013 xffff. All rights reserved.
 *
 */

#include "genprimes.h"

// this will slow down a lot if you make it too big
#define LIMIT  100000000
#define PRIMES 100000000

int* genprimes()
{
  static int primes[PRIMES];
  static int numbers[LIMIT];
  int i,j;
	
  // fill the array with natural numbers
  for(i=0;i<LIMIT;i++)
    numbers[i]=i+2;
	
  // sieve the non-primes
  for(i=0;i<LIMIT;i++)
    if(numbers[i]!=-1)
      for(j=2*numbers[i]-2;j<LIMIT;j+=numbers[i])
	numbers[j]=-1;
	
  // transfer the primes to their own array
  j = 0;
  for (i=0;i<LIMIT&&j<PRIMES;i++)
    if (numbers[i]!=-1)
      primes[j++] = numbers[i];
	
  return primes;
}
