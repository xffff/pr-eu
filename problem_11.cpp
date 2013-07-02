/*
  In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

  08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
  49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
  81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
  52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
  22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
  24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
  32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
  67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
  24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
  21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
  78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
  16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
  86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
  19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
  04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
  88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
  04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
  20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
  20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
  01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

  The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

  What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#define BUFSIZE 256

int main()
{
  int i,j,k,width,height,input;
  int array[BUFSIZE][BUFSIZE];
  double maximum;
  std::string line;
  std::string data[BUFSIZE];
  input=4;

  // grab data from data file
  std::ifstream myfile ("problem_11.dat");
  if(myfile.is_open()){
    i = 0;
    while(myfile.good()){
      std::getline(myfile,line);
      data[i]=line;
      std::cout<<data[i]<<std::endl;
      i++;
    }
    myfile.close();
    height=i;
    std::cout<<"Num rows: "<<height;
  }
  else
    std::cout<<"File Read Error!";
  
  // each element of each line is separated by a space
  // tokenise this using a vector and stringstream
  // this will sanitise the input so I can chuck it in an array
  for(i=0;i<height;i++){
    int buffer; 
    std::stringstream ss(data[i]); // load one line into stream
    std::vector<int> tokens; // this will hold the elements   
    std::vector<int>::iterator it;
    while(ss>>buffer)
      tokens.push_back(buffer);
    for(it=tokens.begin();it!=tokens.end();++it){
      int index = it-tokens.begin();      
      array[i][index]=*it;      
      width=index+1;
    }      
  }
  std::cout<<" Num cols: "<<width<<std::endl;

  std::cout<<"Rows/Cols... \n";
  
  // rows and cols
  for(i=0;i<width;i++){
    for(j=0;j<height-input;j++){
      double rowmax = 1;
      double colmax = 1;
      for(k=0;k<input;k++){
	double temp = maximum;
	rowmax*=array[i][j+k];
	colmax*=array[j+k][i];
	if(rowmax>maximum) maximum=rowmax;	 	 
	if(colmax>maximum) maximum=colmax;	  
	if(maximum>temp) std::cout<<"New maximum: "<<maximum<<std::endl;
      }
    } 
  }
  std::cout<<"Diags...\n";
  
  // now diags
  for(i=0;i<width+height-1;i++){
    int slicearray[width+height-1];
    int temp = 0;    
    for(j=0;j<height;j++){
      for(k=0;k<width;k++){
	if(j+k-i==0){
	  std::cout<<array[j][k]<<" ";
	  slicearray[temp]=array[j][k];
	  temp++;
	}
      }
    }
    std::cout<<std::endl;
    if(temp>input){
      int n;
      double diagmax = 1;
      for(n=0;n<temp;n++){
	if(n%input!=0){ 
	  diagmax*=slicearray[n];
	  if(diagmax>maximum) maximum=diagmax;
	}
      }
    }
  }
  
  std::cout<<"Maximum: "<<maximum<<std::endl;

  return 0;
}

