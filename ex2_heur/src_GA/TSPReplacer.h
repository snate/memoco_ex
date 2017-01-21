/**
 * @file TSPReplacer.h
 * @brief Introduces offspring in the population
 *
 */

#ifndef TSPREPLACER
#define TSPREPLACER

#include <vector>

#include "TSPPopulation.h"
#include "TSPSolution.h"

using namespace std;

/**
 * Class that change the population by adding offspring
 */
class TSPReplacer {

private:

public:
  /** Constructor */
  TSPReplacer() { }

  int eliteSize = 2;

  /**
   * Setter for eliteSize.
   * @param newSize the new size
   */
  void setEliteSize(int newSize) { eliteSize = newSize; }

  /**
   * Introduce offspring in the population.
   * @param pop GA population
   * @param offspring new solutions
   */
  // PRE: pop is ordered
  void replace(TSPPopulation& pop, vector<TSPSolution*> offspring, const TSP& tsp);
  // POST: pop is ordered

};

#endif /* TSPREPLACER */
