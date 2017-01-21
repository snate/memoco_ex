/**
 * @file main.cpp
 * @brief Entry point for Local Search program
 */


#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <sys/time.h>

#include "TSP.h"
#include "TSPSolver.h"
#include "TSPSolution.h"

// error status and messagge buffer
int status;
char errmsg[255];

using namespace std;

int main (int argc, char const *argv[]) {
  try {
    if (argc < 2) throw runtime_error("usage: ./main filename.dat");

    // create the instance (reading data)
    TSP tspInstance;
    tspInstance.read(argv[1]);

    // initialize clocks for running time recording
    //    1) CPU time (t2 - t1)
    clock_t t1, t2;
    t1 = clock();
    // or 2) wall-clock time (tv2 - tv1)
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    // create solver class
    TSPSolver tspSolver;

    // run the neighbourhood search
    TSPSolution bestSolution(tspInstance);
    tspSolver.solve(tspInstance, bestSolution);

    double bestValue = bestSolution.evaluate(tspInstance);
    cout<<"Best solution with obj function value equal to "<<bestValue<<" found ";
    // get execution time
    t2 = clock();
    gettimeofday(&tv2, NULL);
    double executionTime = (double)(t2-t1) / CLOCKS_PER_SEC;
    cout<<"in "<< executionTime << " seconds (CPU time)\n";
    // write execution times to file
    if (argc > 2) {
      ostringstream oss;
      oss << "output/performance_" << argv[2];
      string path = oss.str();
      ofstream logTime;
      logTime.open(path.c_str(), std::ios_base::app);
      logTime << executionTime << "\t" << bestValue << "\n";
    }
  }
  catch(exception& e) {
    cout << ">>>EXCEPTION: " << e.what() << endl;
  }
  return 0;
}
