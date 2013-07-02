/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?
*/

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)
{
  int i,input; 
  double thepow;
  double sum;
  string inputstring;
  ostringstream ss;
  cout<<"Got "<<argc<<" arguments"<<endl;
  if(argc==2){
    input = atoi(argv[1]);
    cout<<"2^"<<input;
    thepow=pow(2,input);
    cout<<"="<<thepow<<endl;
    // convert to string
    ss<<fixed<<thepow;
    inputstring = ss.str();
    cout<<"As string: "<<inputstring<<endl;
    for(i=0;i<inputstring.length();i++){
      int temp = inputstring[i] - '0';      
      if(temp>0){
	sum+=temp;
	cout<<temp<<"+";
      }
    }
    cout<<".0"<endl<<"Sum of individual numbers: "<<sum<<endl;
  }
  else{
    cout<<"Usage: Need one arg"<<endl;
  }
  return 0;
}
