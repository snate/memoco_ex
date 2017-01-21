/**
 * @file TSPRecombinator.cpp
 * @brief Combines parents to generate offspring
 *
 */

#include "TSPRecombinator.h"
#include <iostream>
#include <set>

using namespace std;

TSPSolution* TSPRecombinator::newOffspring(const TSPSolution& parent) {
  srand( time(NULL) );
  uint size = parent.sequence.size();
  vector<int> offspring(size);
  int index0 = rand() % (size - 2);
  int index1 = rand() % (size - 2);
  while(index0 == index1)
    index1 = rand() % size;
  if(index0 > index1) {
    int aux = index0;
    index0 = index1;
    index1 = aux;
  }
  index0++; index1++;
  // 0 < index0 < index1 < size
  for (int i = 0; i < index0; ++i)
    offspring[i] = parent.sequence[i];
  for (uint i = index1; i < size; ++i)
    offspring[i] = parent.sequence[i];
  for (int i = 0; i + index0 < index1; ++i)
    offspring[index0 + i] = parent.sequence[index1 - i - 1];
  return new TSPSolution(offspring);
}

vector<TSPSolution*> TSPRecombinator::
                     newOffspring(TSPSolution* parent0,
                                  TSPSolution* parent1) {
  srand( time(NULL) );
  vector<TSPSolution*> result(2);
  int length = parent0->sequence.size();
  int index0 = rand() % (length - 2);
  int index1 = rand() % (length - 2);
  while(index0 == index1)
    index1 = rand() % length;
  index0++; index1++;
  if(index0 > index1) {
    int aux = index0;
    index0 = index1;
    index1 = aux;
  }
  // 0 < index0 < index1 < size
  result[0] = orderCrossover(parent0, parent1, index0, index1);
  result[1] = orderCrossover(parent1, parent0, index0, index1);
  return result;
}

TSPSolution* TSPRecombinator::orderCrossover(TSPSolution* pOrigin,
                                             TSPSolution* pPivot,
                                             int start, int end) {
  vector<int> sOrigin = pOrigin->sequence;
  vector<int> sPivot = pPivot->sequence;
  vector<int> offspringSequence;
  int length = sPivot.size();
  offspringSequence.resize(length);

  // copy from 0 to start
  for (int i = 0; i < start; i++)
    offspringSequence[i] = sOrigin[i];
  // copy from end to length
  for (int i = end; i < length; i++)
    offspringSequence[i] = sOrigin[i];

  // order crossover in the central part
  set<int> toBeReordered;
  for (int j = start; j < end; ++j)
    toBeReordered.insert(sOrigin[j]);
  int offset = 0;
  for (int k = 0; !toBeReordered.empty(); ++k)
    if(toBeReordered.find(sPivot[k]) != toBeReordered.end()) {
      offspringSequence[start + offset] = sPivot[k];
      offset++;
      toBeReordered.erase(sPivot[k]);
    }
  return new TSPSolution(offspringSequence);
}
