/*
 *  problem_10.c
 *  euler
 *
 *  Created by mike on 25/03/2013.
 *  Copyright 2013 xffff. All rights reserved.
 *
 */

#include <stdio.h>
#include "genprimes.h"

int main()
{
  int input;
  double sum;
  int *primes;
  int i;
  printf("Enter a number: ");
  scanf("%d",&input);
	
  primes = genprimes();
	
  for(i = 0; primes[i]<input; i++){
    if(primes[i]!=0){
      printf("%d Prime %d Sum %.0f\n", i, primes[i], sum);
      sum+=primes[i];
    } 
    else{
      printf("\nBullcrap.. number too big\n");
      return 0;
    }
  }
		
  printf("\n%.0f\n", sum);
	
  return 0;
}
