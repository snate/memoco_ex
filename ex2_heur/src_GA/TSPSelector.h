/**
 * @file TSPSelector.h
 * @brief Extracts parents from population
 *
 */

#ifndef TSPSELECTOR
#define TSPSELECTOR

#include <vector>

#include "TSPSolution.h"
#include "TSPPopulation.h"

using namespace std;

/**
 * Class that provides initial populations for a genetic algorithm.
 */
class TSPSelector {

private:
  vector<int> roulette; // needed for linear ranking
  /**
   * Performs an extraction from the provided vector.
   * @param solutions among which the winner will be extracted
   * @return the winner of the extraction
   */
  TSPSolution* extractParentWithLinearRanking(vector<TSPSolution*> solutions);

public:
  /** Constructor */
  // n is the population size
  TSPSelector(int n) {
    roulette.resize( n * (n+1) / 2 );
    int cnt = 0;
    for(int j = n-1; j >= 0; j--)
      for(int i = 0; (n-i) > j; i++) {
        roulette[cnt] = j;
        cnt++;
      }
  }

  /**
   * Returns a couple of parents.
   * @param pop GA population
   */
  vector<TSPSolution*> takeTwoParents(const TSPPopulation& pop);
  // POSTCONDITION: `result HAS EXACTLY TWO PARENTS

};

#endif /* TSPSELECTOR */
