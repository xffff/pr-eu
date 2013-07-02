/*

  The prime factors of 13195 are 5, 7, 13 and 29.
 
  What is the largest prime factor of the number 600851475143?
 
*/

#include<iostream>
#include<vector>
#include<math.h>
#include<gmp.h>
#include "primesieve.h"

using namespace std;

int main(int argc, char** argv)
{
  if(argc == 2){
    vector<int> primes;
    double input = atol(argv[1]);
    int primecount = 0;

    // gen primes
    primesieve(primes, (int)input);
    cout<<"Number of Primes: "<<primes.size()<<endl;

    // get factors
    for(int i=0; i<input&&i<primes.size(); ++i){
      int thisprime = primes.at(i);
      double thisfactor = input/thisprime;
      //cout<<i<<" "<<thisprime<<endl;
      if(fmod(input,thisprime)==0){	
	cout<<"Prime "<<thisprime<<" Factor "<<thisfactor<<endl;
	primecount+=1;
      }
    }
  } else {
    cout<<"Usage: "<<argv[0]<<" number"<<endl;
  }
  return 0;
}
