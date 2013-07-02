/*
 *  problem_4.c
 *  euler
 *
 
 A palindromic number reads the same both ways. 
 The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 
 Find the largest palindrome made from the product of two 3-digit numbers.
 
 *  Created by mike on 18/03/2013.
 *  Copyright 2013 xffff. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void reverse(char* start);

int main()
{
  int input,length,i,j;
	
	printf("Enter a maximum: ");
	scanf("%d", &input);
	length = floor(log10(abs(input))) + 1;;
	
	for(i = (input-input*0.1); i<input; ++i){
		char string[length], reversed[length]; 
		
		for(j = (input-input*0.1); j<input; ++j){
			int num = i*j;
			
			// we have to do a conversion to string every time to reverse
			sprintf(string, "%d", num);
			strcpy(reversed,string);
			reverse(reversed);
			if(strncmp(reversed,string,length)==0){
				printf("%d * %d = %s, reversed: %s", i, j, string, reversed);
				printf("\n");
			}
		}
	}
	return 0;
}

void reverse(char* string) {
	char temp;
	char* end;
	end = string + strlen(string)-1;
	while(end>string){
		temp=*end;
		*end=*string;
		*string=temp;
		end--;
		string++;
	}
}
