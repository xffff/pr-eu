/*
 *  problem_8.c
 *  euler
 *
 *  Created by mike on 24/03/2013.
 *  Copyright 2013 xffff. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 51

int main()
{
  FILE *f; 
  int maximum = 0;
	
  // grab line if file exists
  if((f=fopen("problem_8_data.dat","r")) != NULL){
    int i = 0;
    char buffer[MAX];

    while(!feof(f) && fgets(buffer,MAX,f) != NULL){
      // data is now in buffer...
      // store 5 elements and multiply them together
      // saving the maximum to compare with result
      int fivenums[5];
      int j, k;
    
      printf("\nString read: %s", buffer);

      for(j = 0; j < 46; j++){
	int thismax = 1;
	for(k = 0; k < 5; k++){
	  char ctemp;
	  int itemp;
	  ctemp = buffer[j+k];
	  fivenums[k] = ctemp - '0';
	  /// there is a problem here iwth newline chars I know it
	  if(fivenums[k]>=0){
	    int itemp;
	    // current max
	    itemp = thismax;
	    thismax *= fivenums[k];
	    printf("\n%d %d %d maximum: %d thismax: %d = %d * %d", 
		   i, j, k, maximum, thismax, itemp, fivenums[k]);
	  }       
	  // store running max if changed
	  if(thismax > maximum){
	    maximum = thismax;
	    printf("\nNew maximum!: %d", maximum);
	  }
	}
	i++;
      }
    }
  }
  else{
    printf("Read Error!\n");
  }

  // close file
  fclose(f);

  // print maximum
  printf("\nThe maximum value was: ", maximum);
  printf("\n");

  return 0;
}

