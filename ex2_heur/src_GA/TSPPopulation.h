/**
 * @file TSPPopulation.h
 * @brief Population representation for GAs
 *
 */

#ifndef TSPPOPULATION
#define TSPPOPULATION

#include <vector>

#include "TSPSolution.h"

using namespace std;

/**
 * Class that provides initial populations for a genetic algorithm.
 */
class TSPPopulation {
public:
  /** Constructor */
  TSPPopulation ( ) { }

  vector<TSPSolution*> population;

  /**
   * Generates n solutions as initial population
   * @param tsp TSP data
   * @param n size of initial population
   */
  void initialPopulation(const TSP& tsp, int n);

  /**
   * Orders the population ranking elements thanks to their fitness.
   * @param tsp TSP data
   */
  void orderPopulation(const TSP& tsp);

  /**
   * Prints the best 10 (or less) elements of the population, ranked by fitness
   */
  void printBestOfPopulation();

  void setHeurGeneratedPopulation(int num) { createdWithHeur = num; }

private:
  int createdWithHeur = 1;
  void initRnd(const TSP& tsp, TSPSolution& solution);
  void initHeur(const TSP& tsp, TSPSolution& solution);
};

#endif /* TSPPOPULATION */
