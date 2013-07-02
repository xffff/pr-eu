/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?
 */

#include <stdio.h>
#include <math.h>

int main()
{
  int input,maxchain,maxnum,i;
  printf("\nEnter max collatz: \n");
  scanf("%d",&input);
  maxchain=0;
  maxnum=0;
  for(i=0;i<input+1;i++){
    double thiscollatz=i;
    int j = 2;
    while(thiscollatz>1){
      if(fmod(thiscollatz,2)==0)
	thiscollatz/=2;
      else
	thiscollatz=thiscollatz*3+1;
      //printf("Start %d Chainlen %d CollatzNum %d\n",i,j,thiscollatz);
      j++; 
    }
    if(j>maxchain){
      maxchain=j;
      maxnum=i;
      printf("New max chainlen! %d - %d\n",maxnum,maxchain);
    }
  }
  printf("Max Collatz Chain Length: %d\nNumber: %d\n", maxchain,maxnum);
  return 0;
}

