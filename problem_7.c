/*
 *  problem_7.c
 *  euler
 *
 *  Created by mike on 24/03/2013.
 *  Copyright 2013 xffff. All rights reserved.
 *
 */

#include <stdio.h>
#include "genprimes.h"

int main()
{
	int* primes;
	int input;
	
	primes = genprimes();
	
	printf("Input the index of the prime you want: ");
	scanf("%d",&input);
	input--;
	printf("\n Answer: %d", primes[input]);
	printf("\n");	
	return 0;
}

