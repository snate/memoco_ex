/**
 * @file TSPReplacer.cpp
 * @brief Provides a couple of parents for the GA
 *
 */

#include "TSPReplacer.h"
#include <iostream>

using namespace std;

// PRE: `pop IS ORDERED
void TSPReplacer::
     replace(TSPPopulation& pop, vector<TSPSolution*> offspring, const TSP& tsp) {
  // Replace with elitism
  while(!offspring.empty()) {
    int index = rand() % (pop.population.size() - eliteSize) + eliteSize;
    delete(pop.population[index]);  // free memory because element will be removed
    pop.population[index] = offspring[0];
    offspring.erase(offspring.begin());
  }
  pop.orderPopulation(tsp); // enforces post-condition
}
  // POST: `pop IS ORDERED
