/**
 * @file TSP.h
 * @brief TSP data representation
 */

#ifndef TSP_H
#define TSP_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Class that describes a TSP instance (a cost matrix in which nodes are
 * identified by integers 0 .. n-1).
 */
class TSP {
public:
  TSP() : n(0) , infinite(1e10) { }

  int n; //number of nodes
  vector< vector<double> > cost;
  double infinite; // infinite value (an upper bound on the value of any feasible solution)

  void read(const char* filename) {
    ifstream in(filename);
    // read size
    in>>n;
    cout<< "Number of nodes: " << n <<endl;
    // read costs
    cost.resize(n);
    for (int i = 0; i < n; i++) {
      cost[i].reserve(n);
      int nil;
      in>>nil; // ignore node identifier
      for (int j = 0; j < n; j++) {
        double c;
        in>>c;
        cost[i].push_back(c);
      }
    }
    in.close();
  }
};

#endif /* TSP_H */
