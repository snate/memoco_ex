/**
 * @file generator_rg.cpp
 * @brief random grid data generator for drilling problem that uses Manhattan
 *        distances
 */

#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class IllegalArgumentException {
};

vector<vector<int> > randSymmMatrixGen(int holes, int size, int divisions) {
  int boardSize = 2 * holes * size;
  int cellSize = boardSize / divisions;
  srand(time(NULL));
  vector<int> xPositions;
  vector<int> yPositions;
  xPositions.resize(holes);
  yPositions.resize(holes);
  // generate positions
  for (int i = 0; i < holes; i++) {
    xPositions[i] = rand() % cellSize;
    yPositions[i] = rand() % cellSize;
  }
  // add offsets due to grid layout
  // may be meld with the previous for cycle to compact code
  int holesPerZone = holes / (divisions * divisions);
  int zone = 0;
  for (int i = 0; i < holes; i++) {
    xPositions[i] = xPositions[i] + cellSize * (zone % divisions);
    yPositions[i] = yPositions[i] + cellSize * (zone / divisions);
    if (i >= holesPerZone* (zone+1))
      zone++;
  }
  vector<vector<int> > distancesMatrix;
  distancesMatrix.resize(holes);
  for (int i = 0; i < holes; i++) {
    distancesMatrix[i].resize(holes);
    distancesMatrix[i][i] = 0;
  }
  for (int i = 0; i < holes; i++)
    for (int j = 0; j < i; j++) {
      int xDiff = abs(xPositions[i] - xPositions[j]);
      int yDiff = abs(yPositions[i] - yPositions[j]);
      distancesMatrix[i][j] = distancesMatrix[j][i] = xDiff + yDiff;
    }
  return distancesMatrix;
}

int main(int argc, char* argv[]) {
  if(argc < 4) throw new IllegalArgumentException();
  cout<<"Generating "<<argv[1]<<" holes ";
  cout<<"for a "<<argv[2]<<"x-sized grid ";
  cout<<"with "<<argv[3]<<" divisions..."<<endl;
  int holes = (int) strtol(argv[1], NULL, 0);
  int size = (int) strtol(argv[2], NULL, 0);
  int zonesPerDim = (int) strtol(argv[3], NULL, 0);
  ofstream file;
  file.open("../instances/rg_data_Manh.dat");
  file<<holes<<endl;
  vector<vector<int> > distances = randSymmMatrixGen(holes, size, zonesPerDim);
  for(int i=0; i < holes; i++) {
    file<<i;
    for (int j = 0; j < holes; j++)
      file<<'\t'<<distances[i][j];
    file<<endl;
  }
  file.close();
  return 0;
}
