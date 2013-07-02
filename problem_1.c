/* 
   Euler Problem 1 
   If we list all the natural numbers below 10 that are multiples of 3 or 5, 
   we get 3, 5, 6 and 9. The sum of these multiples is 23.
 
   Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>
#include <ctype.h>

int main () {
  int sum = 0;
  int input = 0;
  int i;

  printf("Euler Problem 1\n");
  printf("Input a number: ");
	
  scanf("%d", &input);
	
  for(i = 0; i<input; ++i){
    if(i%3==0 || i%5==0){
      sum = sum + i;
      printf("Sum %d: %d", i, sum);
      printf("\n");
    };
  };
	
  return 0;
}
