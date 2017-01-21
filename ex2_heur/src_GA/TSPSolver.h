/**
 * @file TSPSolver.h
 * @brief TSP solver (neighbourhood search)
 *
 */

#ifndef TSPSOLVER_H
#define TSPSOLVER_H

#include <vector>
#include <ctime>

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
  bool solve(const TSP& tsp, TSPSolution& bestSol);

protected:
  /**
   * explore the neighbouhood
   * @param tsp TSP data
   * @param currSol center solution
   * @return (into param move) the selected move (stepest descent strategy)
   * @return the incremental cost with respect to currSol
   */
  double findBestNeighbor(const TSP& tsp, const TSPSolution& currSol, TSPMove& move);

};

#endif /* TSPSOLVER_H */
