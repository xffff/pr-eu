/*
 *  problem_6.c
 *  euler
 *
 *  Created by mike on 24/03/2013.
 *  Copyright 2013 xffff. All rights reserved.
 *
 */

#include <stdio.h>
#include <math.h>

int main()
{
	int input;
	int sumsquare=0;
	int squaresum=0;
	int i; 
	
	printf("Enter the range 1-x to work out sum sq difference: ");
	scanf("%d",&input);	
	for(i=1;i<=input;i++){
		// work out sum of squares
		sumsquare += i*i;
		printf("\n%d Current sumsquare: %d", i, sumsquare);
		squaresum += i;
	}
	i--;

	printf("\nSquaresum = %d * %d", i, i);
	squaresum*=squaresum;
	printf("\nSquaresum %d Sumsquare %d Difference %d", 
		   squaresum, sumsquare, (squaresum-sumsquare));
	printf("\n");
	return 0;
}

