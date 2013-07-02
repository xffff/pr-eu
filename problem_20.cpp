/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include<iostream>
#include<gmp.h>

using namespace std;

int main(int argc, char** argv)
{
  if(argc == 2){
    int i = 0;
    int limit = atoi(argv[1]);
    mpz_t factorial;
    int sum;
    char ich[1024];
    mpz_init_set_ui(factorial,limit);

    for(i = limit-1; i > 1; --i){
      // find factorial
      mpz_mul_ui(factorial,factorial,i);
      gmp_printf("%Zd\n", factorial);
    }
    
    // convert this big number to a char array
    mpz_get_str(ich,10,factorial);

    // iterate through and find sum
    for(i = 0; ich[i]!='\0'; ++i){
      int temp = ich[i]-'0';
      sum += temp;
      cout<<temp<<" ";
    }

    cout<<endl<<sum<<endl;
    mpz_clear(factorial);
  } else {
    cout<<"Error: need 2 args\n";
  }
  return 0;
}
