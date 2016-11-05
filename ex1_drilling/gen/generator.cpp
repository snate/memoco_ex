/**
 * @file generator.cpp
 * @brief data generator for drilling problem
 */

#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class IllegalArgumentException {
};

vector<vector<int> > randSymmMatrixGen(int dim) {
  vector<vector<int> > matrix;
  matrix.resize(dim);
  for (int i = 0; i < dim; i++) {
    matrix[i].resize(dim);
    matrix[i][i] = 0;
  }
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < i; j++)
      matrix[i][j] = matrix[j][i] = rand() % 100 + 1;
  return matrix;
}

int main(int argc, char* argv[]) {
  if(argc < 2) throw new IllegalArgumentException();
  cout<<"Generating "<<argv[1]<<" numbers..."<<endl;
  int limit = *argv[1] - '0';
  ofstream file;
  file.open("../data");
  vector<vector<int> > distances = randSymmMatrixGen(limit);
  for(int i=0; i < limit; i++) {
    file<<i;
    for (int j = 0; j < limit; j++)
      file<<'\t'<<distances[i][j];
    file<<endl;
  }
  file.close();
  return 0;
}
