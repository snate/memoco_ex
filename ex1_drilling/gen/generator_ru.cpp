/**
 * @file generator_ru.cpp
 * @brief random uniform data generator for drilling problem
 */

#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class IllegalArgumentException {
};

vector<vector<int> > randSymmMatrixGen(int dim, int boardSize) {
  boardSize = boardSize * dim * dim;
  srand(time(NULL));
  vector<vector<int> > matrix;
  matrix.resize(dim);
  for (int i = 0; i < dim; i++) {
    matrix[i].resize(dim);
    matrix[i][i] = 0;
  }
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < i; j++)
      matrix[i][j] = matrix[j][i] = rand() % boardSize + 1;
  return matrix;
}

int main(int argc, char* argv[]) {
  if(argc < 3) throw new IllegalArgumentException();
  cout<<"Generating "<<argv[1]<<" numbers ";
  cout<<"for a "<<argv[2]<<"x-sized board..."<<endl;
  int limit = (int) strtol(argv[1], NULL, 0);
  int size = (int) strtol(argv[2], NULL, 0);
  ofstream file;
  file.open("../instances/ru_data.dat");
  file<<limit<<endl;
  vector<vector<int> > distances = randSymmMatrixGen(limit, size);
  for(int i=0; i < limit; i++) {
    file<<i;
    for (int j = 0; j < limit; j++)
      file<<'\t'<<distances[i][j];
    file<<endl;
  }
  file.close();
  return 0;
}
