/*

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

 */

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "primesieve.h"

using namespace std;

string convertint(int number)
{
  stringstream ss;
  ss<<number;
  return ss.str();
}

int convertstring(string astring)
{
  int number;
  istringstream(astring)>>number;
  return number;
}

string myrotate(string &s)
{
  for(int i=1;i<s.size();i++)
    swap(s[i-1],s[i]);
  return s;
}

int main(int argc, char** argv)
{
  if(argc==2){
    vector<int> primes;
    int limit = atoi(argv[1]);
    int cprimesum = 0;
    int numprimes;
    primesieve(primes, limit);
    numprimes = primes.size();
    for(int i=0;i<numprimes;i++){
      int thisprime = primes.at(i);
      string digits = convertint(thisprime);
      int numdigits = digits.size();
      bool noevennums = true; // check for 2,4,6,8 in the prime
      
      if(i>5){
	for(int j=0;j<numdigits;j++){
	  int thisdigit = digits[j] - '0';
	  if(thisdigit%2==0 || thisdigit==5)
	    noevennums = false;
	}
      }

      if(noevennums){	
	int thiscprimesum = 0;

	// rotate!
	for(int j=0;j<numdigits;j++){
	  int rthisprime;
	  // string temp = rotate(digits.begin(),digits.begin()+1,digits.end());
	  myrotate(digits);
	  rthisprime = atoi(digits.c_str());

	  // now check this rotation is equal
	  // to one of the primes in the vector
	  for(int k=0;k<numprimes;k++){	  
	    if(rthisprime==primes.at(k)){
	      thiscprimesum++;	    
	    }
	  }
	
	  // if primecount == digits.length()
	  // we have a circular prime!!!
	  if(thiscprimesum == numdigits){
	    cprimesum++;
	    cout<<"Circular Prime "<<cprimesum<<": "<<digits<<endl;	  
	  }
	}
      }
    }
  } else {
    cout<<"Usage: "<<argv[0]<<" limit\n";
  }
  return 0;
}
