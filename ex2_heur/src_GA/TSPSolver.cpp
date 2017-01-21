/**
 * @file TSPSolver.cpp
 * @brief TSP solver (neighborhood search)
 *
 */

#include "TSPSolver.h"
#include "TSPPopulation.h"
#include "TSPRecombinator.h"
#include "TSPReplacer.h"
#include "TSPSelector.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <sys/time.h>

using namespace std;

bool TSPSolver::solve(const TSP& tsp, TSPSolution& bestSol) {

  TSPRecombinator recombinator = TSPRecombinator();
  TSPReplacer replacer = TSPReplacer();

  setPopulationSize(10);      // tuning
  setTimeLimit(50) ;          // tuning
  setMutationThreshold(0.5);  // tuning
  replacer.setEliteSize(1);   // tuning

  struct timeval tv1, tv2;
  gettimeofday(&tv1, NULL);
  TSPPopulation population = TSPPopulation();
  population.initialPopulation(tsp, populationSize);
  gettimeofday(&tv2, NULL);
  double diff = (double) (tv2.tv_sec + tv2.tv_usec*1e-6 - (tv1.tv_sec+tv1.tv_usec*1e-6));
  TSPSelector aSelector = TSPSelector(populationSize);
  while(diff < timeLimit) {
    vector<TSPSolution*> parents = aSelector.takeTwoParents(population);
    vector<TSPSolution*> offspring = recombinator.newOffspring(parents[0],
                                                               parents[1]);
    vector<TSPSolution*>::iterator it = population.population.begin();
    while(it != population.population.end()) {
      if(mutationThreshold > rand() % bigNumber) {
        TSPSolution* newElem = recombinator.newOffspring(**it);
        offspring.resize(offspring.size() + 1);
        offspring[offspring.size() - 1] = newElem;
      }
      ++it;
    }
    replacer.replace(population, offspring, tsp);
    gettimeofday(&tv2, NULL);
    diff = (double) (tv2.tv_sec+tv2.tv_usec*1e-6 - (tv1.tv_sec+tv1.tv_usec*1e-6));
  }
  population.printBestOfPopulation();
  bestSol = *(population.population[0]);
  return true;
}

double TSPSolver::findBestNeighbor(const TSP& tsp, const TSPSolution& currSol, TSPMove& move) {
/* Determine the *move* yielding the best 2-opt neighbor solution
 */
  double bestCostVariation = tsp.infinite;
  /// incremental evaluation --> bestCostVariation (instead of best cost)

  for(uint a = 1; a < currSol.sequence.size() - 2; a++)
    for(uint b = a+1; b < currSol.sequence.size() - 1; b++) {
      int h = currSol.sequence[a-1];
      int i = currSol.sequence[a];
      int j = currSol.sequence[b];
      int l = currSol.sequence[b+1];
      double c_hj = tsp.cost[h][j];
      double c_il = tsp.cost[i][l];
      double c_hi = tsp.cost[h][i];
      double c_jl = tsp.cost[j][l];
      double currentCostVariation = c_hj + c_il - c_hi - c_jl;
      if(currentCostVariation < bestCostVariation) {
        move.from = a;
        move.to = b;
        bestCostVariation = currentCostVariation;
      }
    }
  return bestCostVariation;
}
