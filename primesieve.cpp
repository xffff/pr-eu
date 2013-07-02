/* prime sieve from wiki */
// primes is a list of primes, n is all the primes you want to generate.. from 2 to n

#include <cmath>
#include <vector>

using namespace std;

void primesieve(vector<int> &primes, int n){
  for(int i=2;i<=n;i++){
    int root = (int)(sqrt(i))+1;    // remember the square root
    bool found = false;       // prime found?
    vector<int>::const_iterator it;
    for(it = primes.begin(); it!=primes.end() && *it<root; it++){
      if(i % *it == 0){
	found = true; // this is not prime
	break;  
      }  
    }
    if(!found) primes.push_back(i); // this is a prime, put it in the vector
  }
}
