/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>
#include "lcm.h"

int main()
{
  int input, i, temp;
  printf("Find LCM of 1 .. ");
  scanf("%d",&input);
  temp=lcm(1,2);
  for(i=2;i<input;i++){
    temp=lcm(temp,i);
    printf("1 .. %d lcm %d\n", i, temp);
  }
  return 0;
}


