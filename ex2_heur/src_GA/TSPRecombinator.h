/**
 * @file TSPRecombinator.h
 * @brief Combines parents to generate offspring
 *
 */

#ifndef TSPRECOMBINATOR
#define TSPRECOMBINATOR

#include <vector>

#include "TSPSolution.h"

using namespace std;

/**
 * Class that combines one or more parents to generate offspring
 */
class TSPRecombinator {
private:
/**
   * Utility method that performs an order crossover.
   */
  TSPSolution* orderCrossover(TSPSolution* pOrigin,
                              TSPSolution* pPivot,
                              int start, int end);

public:
  /** Constructor */
  TSPRecombinator() { }

  /**
   * Generates offspring out of a parent (mutation).
   * @param pop GA population
   */
  TSPSolution* newOffspring(const TSPSolution& parent);

  /**
   * Generates offspring from two parents.
   * @param pop GA population
   */
  vector<TSPSolution*> newOffspring(TSPSolution* parent0,
                                    TSPSolution* parent1);

};

#endif /* TSPRECOMBINATOR */
