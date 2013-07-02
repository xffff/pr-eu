/*
The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <iostream>
#include <math.h>
#include <gmp.h>
using namespace std;

int main(int argc, char** argv)
{
  if(argc==2){
    int i,input;
    int length;
    mpz_t thisfib;
    size_t thissize;
    input = atoi(argv[1]);
    length = 1;
    mpz_init_set_ui(thisfib,1);
    for(i=0;thissize<input;++i){
      mpz_fib_ui(thisfib,i);
      thissize = mpz_sizeinbase(thisfib,10);
      //length = floor(log10(abs(fib[0]))) + 1;
    }
    gmp_printf("Term: %d Fib: %Zd\n", i, thisfib);
    mpz_clear(thisfib);
  }
  else{
    cout<<"Usage: "<<argv[0]<<" length\n";
  }
  return 0;
}
