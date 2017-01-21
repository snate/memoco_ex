/**
 * @file main.cpp
 * @brief Entry point for Local Search program
 */


#include <stdexcept>
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

    // final clocks
    t2 = clock();
    gettimeofday(&tv2, NULL);

    double ut = (double) (tv2.tv_sec+tv2.tv_usec*1e-6 - (tv1.tv_sec+tv1.tv_usec*1e-6));
    cout<<"in "<< ut << " seconds (user time)\n";
    cout<<"in "<< (double)(t2-t1) / CLOCKS_PER_SEC << " seconds (CPU time)\n";
    
  }
  catch(exception& e) {
    cout << ">>>EXCEPTION: " << e.what() << endl;
  }
  return 0;
}
