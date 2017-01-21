/**
 * @file TSPPopulation.cpp
 * @brief Represents a population for genetic algorithms
 *
 */

#include "TSPPopulation.h"
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

void TSPPopulation::
     initialPopulation(const TSP& tsp, int n) {
  srand( time(NULL) );
  for(int i = 0; i < n; i++)
    population.push_back(new TSPSolution(tsp));
  for (int i = 0; i < createdWithHeur; ++i) {
    initHeur(tsp, *population[i]);
  }
  for(int i = createdWithHeur; i < n; i++)
    initRnd(tsp, *population[i]);
  orderPopulation(tsp);
}

void TSPPopulation::orderPopulation(const TSP& tsp) {
  // insertion sort
  int j;
  TSPSolution* temp;
  for(uint i = 0; i < population.size(); i++){
    j = i;
    while(j > 0 && population[j]->evaluate(tsp) < population[j-1]->evaluate(tsp)){
      temp = population[j];
      population[j] = population[j-1];
      population[j-1] = temp;
      j--;
    }
  }
}

void TSPPopulation::printBestOfPopulation() {
  uint howMany = 10;
  if(population.size() < howMany) howMany = population.size();
  cout<<"Hereafter the best elements in the population will be displayed:"<<endl;
  TSPSolution* best = population[0];
  cout<<"*** 0) "; best->print(); cout<<endl;
  for (uint i = 1; i < howMany; ++i) {
    TSPSolution* curr = population[i];
    cout<<"    "<<i<<") "; curr->print(); cout<<endl;
  }
}

void TSPPopulation::initRnd(const TSP &tsp, TSPSolution &solution) {
  vector<int> aux(tsp.n);
  vector<int> newSeq(tsp.n + 1);
  for(int i = 0; i < tsp.n; i++) aux[i] = i;
  random_shuffle(aux.begin(), aux.end() );
  for (int i = 0; i < tsp.n; ++i)
    newSeq[i] = aux[i];
  newSeq[tsp.n] = newSeq[0];
  solution = TSPSolution(newSeq);
}

void TSPPopulation::initHeur(const TSP &tsp, TSPSolution &solution) {
  // Simulated Annealing
  TSPSolution s = TSPSolution(solution);
  int times = tsp.n;
  for (int k = 0; k < times; ++k) {
    TSPSolution sNew = TSPSolution(s);
    sNew.becomeCloseNeighbour();
    double evalS = s.evaluate(tsp);
    double evalSNew = sNew.evaluate(tsp);
    double score = exp (evalS * evalSNew / (times / (k + 1) * 2));
    double threshold = (double) (rand() / RAND_MAX);
    if(score >= threshold)
      s = sNew;
  }
  solution = TSPSolution(s);

}
