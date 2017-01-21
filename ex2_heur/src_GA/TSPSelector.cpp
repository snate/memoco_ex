/**
 * @file TSPSelector.cpp
 * @brief Provides a couple of parents for the GA
 *
 */

#include "TSPSelector.h"
#include <iostream>
#include <algorithm>

using namespace std;

vector<TSPSolution*> TSPSelector::
                    takeTwoParents(const TSPPopulation& pop) {
  vector<TSPSolution*> result;
  result.resize(2);
  TSPSolution* firstParent = extractParentWithLinearRanking(pop.population);
  TSPSolution* secondParent;
  do
    secondParent = extractParentWithLinearRanking(pop.population);
  while((*firstParent).sequence == (*secondParent).sequence);
  result[0] = firstParent;
  result[1] = secondParent;
  return result;
}
// POSTCONDITION: `result HAS EXACTLY TWO PARENTS

// PRECONDITION: `solutions MUST BE AN "ORDERED" VECTOR
TSPSolution* TSPSelector::
            extractParentWithLinearRanking(vector<TSPSolution*> solutions) {
  random_shuffle( roulette.begin(), roulette.end() );
  int winner = roulette[0];
  return solutions[winner];
}
