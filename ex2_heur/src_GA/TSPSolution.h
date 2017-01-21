/**
* @file TSPSolution.h
* @brief TSP solution representation
*
*/

#ifndef TSPSOLUTION_H
#define TSPSOLUTION_H

#include <vector>

#include "TSP.h"

using namespace std;

/**
* TSP Solution representation: ordered sequence of nodes (path representation)
*/
class TSPSolution {

public:
  vector<int> sequence;

public:
  TSPSolution () { }

  /** Constructor 
  * build a standard solution as the sequence <0, 1, 2, 3 ... n-1, 0>
  * @param tsp TSP instance
  */
  TSPSolution(const TSP& tsp) {
    sequence.resize(tsp.n + 1);
    for(int i = 0; i < tsp.n; i++)
      sequence[i] = i;
    sequence[tsp.n] = 0;
  }

  /** Constructor 
  * Copies the sequence given as generator for the solution.
  * @param v sequence to be copied
  */
  TSPSolution(const vector<int> v) {
    sequence.resize(v.size());
    for( uint i = 0; i < v.size() ; i++ )
      sequence[i] = (v[i]);
  }

  /** Copy constructor 
  * build a solution from another
  * @param tspSol TSP solution
  */
  TSPSolution(const TSPSolution& tspSol) {
    sequence.reserve(tspSol.sequence.size());
    for ( uint i = 0; i < tspSol.sequence.size(); ++i )
      sequence[i] = tspSol.sequence[i];
  }

public:

  /**
   * evaluate a solution
   * @param sol: solution to be evaluated
   * @param TSP: TSP data
   * @return the value of the solution
   */
  double evaluate(const TSP& tsp) const {
    double total = 0.0;
    for(uint i = 0 ; i < sequence.size() - 1; i++) {
      int from = sequence[i];
      int to   = sequence[i+1];
      // crasha qui
      // (gdb) print sequence
      // $2 = std::vector of length 13, capacity 13 = {7, 8, 11, 10, 9, 6, 1, 0, 4, 5, 822686986, 7, 2}
      total   += tsp.cost[from][to];
    }
    return total;
  }

  /** print method
  * @param ---
  */
  void print() {
    for ( uint i = 0; i < sequence.size(); i++ ) {
      cout << sequence[i] << " ";
    }
  }

  /** assignment method 
  * copy a solution into another one
  * @param right TSP solution to get into
  * @return ---
  */
  TSPSolution& operator=(const TSPSolution& right) {
    // Handle self-assignment:
    if(this == &right) return *this;
    for ( uint i = 0; i < sequence.size(); i++ )
      sequence[i] = right.sequence[i];
    return *this;
  }
};

#endif /* TSPSOLUTION_H */
