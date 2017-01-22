/**
 * @file TSPSolver.h
 * @brief TSP solver (neighbourhood search)
 *
 */

#ifndef TSPSOLVER_H
#define TSPSOLVER_H

#include <vector>
#include <ctime>

#include "TSPPopulation.h"
#include "TSPReplacer.h"
#include "TSPSolution.h"

/**
 * Class representing substring reversal move
 */
typedef struct move {
  int from;
  int to;
} TSPMove;

using namespace std;

/**
 * Class that solves a TSP problem by neighbourdood search and 2-opt moves
 */
class TSPSolver {
private:
  int populationSize;
  double timeLimit;
  int mutationThreshold;
  int bigNumber = 10000;

public:
  /** Constructor */
  TSPSolver ( ) { }

  void setPopulationSize(int _size) { populationSize = _size; }
  void setTimeLimit(int _limit) { timeLimit = _limit; }
  void setMutationThreshold(double thresh) { mutationThreshold = bigNumber * thresh; }

  /**
   * search for a good tour by neighbourhood search
   * @param TSP TSP data
   * @param initSol initial solution
   * @param bestSol best found solution (output)
   * @return true id everything OK, false otherwise
   */
  bool solve(const TSP& tsp, TSPSolution& bestSol, const char* conf);

protected:
  /**
   */
  void loadConfig(const char* conf, TSPPopulation population, TSPReplacer replacer) {
    ifstream input(conf);
    int a;
    double b;
    input >> a;
    setPopulationSize(a);
    cout << "Population size: " << a << endl;
    input >> a;
    setTimeLimit(a);
    cout << "Time limit (seconds): " << a << endl;
    input >> b;
    setMutationThreshold(b);
    cout << "Mutation threshold: " << b*100 << "%" << endl;
    input >> a;
    population.setHeurGeneratedPopulation(a);
    cout << "Population generated with heuristics: " << a << endl;
    input >> a;
    replacer.setEliteSize(a);
    cout << "Elite size: " << a << endl;
  }

};

#endif /* TSPSOLVER_H */
