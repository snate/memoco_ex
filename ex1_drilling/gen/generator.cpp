/**
 * @file generator.cpp
 * @brief data generator for drilling problem
 */

#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

class IllegalArgumentException {
};

int main(int argc, char* argv[]) {
  if(argc < 2) throw new IllegalArgumentException();
  cout<<"Generating "<<argv[1]<<" numbers..."<<endl;
  int limit = *argv[1] - '0';
  ofstream file;
  file.open("../data");
  for(int i=0; i < limit; i++)
    file<<i<<'\t'<<(rand() % 100 + 1)<<endl;
  file.close();
  return 0;
}
