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

  TSPPopulation population = TSPPopulation();
  TSPRecombinator recombinator = TSPRecombinator();
  TSPReplacer replacer = TSPReplacer();

  population.setHeurGeneratedPopulation(2);
  setPopulationSize(10);      // tuning
  setTimeLimit(10) ;          // tuning
  setMutationThreshold(0.8);  // tuning
  replacer.setEliteSize(1);   // tuning

  TSPSelector aSelector = TSPSelector(populationSize);

  struct timeval tv1, tv2;
  gettimeofday(&tv1, NULL);
  population.initialPopulation(tsp, populationSize);
  gettimeofday(&tv2, NULL);
  double diff = (double) (tv2.tv_sec + tv2.tv_usec*1e-6 - (tv1.tv_sec+tv1.tv_usec*1e-6));
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
