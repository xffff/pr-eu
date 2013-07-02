/*
 *  problem_9.c
 *  euler
 *

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

 *  Created by mike on 25/03/2013.
 *  Copyright 2013 xffff. All rights reserved.
 *
 */

#include <stdio.h>

int main()
{
  int a,b,c,input;
  printf("a+b+c = ");
  scanf("%d",&input);

  // find pythagorean triplets such that a+b+c=1000
  for(a=1;a<input;a++){
    int asq,bsq,csq;
    asq=a*a;
    for(b=1;b<input;b++){
      bsq=b*b;
      for(c=1;c<input;c++){
	csq=c*c;
	if(a+b+c==input && asq<bsq && bsq<csq && asq+bsq==csq){
	  printf("The product of abc is: %d\n",a*b*c);	
	}
      }
    }
  }

  return 0;
}
