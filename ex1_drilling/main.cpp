/**
 * @file main.cpp
 * @brief first exercise for 2016/2017 MEMOCO course
 *
 *    A
 *    |
 *    |
 *    |
 *    B--------C
 *    Distances: A-B = 3, B-C = 4, A-C = 5
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include "cpxmacro.h"

using namespace std;

// error status and messagge buffer
int status;
char errmsg[BUF_SIZE];

// data
const int H = 3; // holes number
const char nameH[H] = { 'A', 'B', 'C' }; // holes' names
// TODO: write following data in a more concise way
// reminder: if data is arranged as follows, this matrix _must_ be symmetric
const double C[H*H] =
    { 0.0, 3.0, 5.0,
      3.0, 0.0, 4.0,
      5.0, 4.0, 0.0 }; // distances between holes

const int NAME_SIZE = 512;
char name[NAME_SIZE];

void setupLP(CEnv env, Prob lp) {
  // add x_{i,j} positive integer variables
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < H; j++) {
      char xtype = 'I';
      double lb = 0.0;
      double ub = CPX_INFBOUND;
      snprintf(name, NAME_SIZE, "x_%c,%c", nameH[i], nameH[j]);
      char* xname = (char*)(&name[0]);
      CHECKED_CPX_CALL(CPXnewcols, env, lp, 1, &C[i*H+j], &lb, &ub, &xtype,
          &xname);
      // status = CPXnewcols (env, lp, ccnt, obj, lb, ub, xctype, colname);
    }
  }

  int ystart = CPXgetnumcols(env, lp);
  // add y_{i,j} boolean variables
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < H; j++) {
      char ytype = 'B';
      double lb = 0.0;
      double ub = 1.0;
      snprintf(name, NAME_SIZE, "y_%c,%c", nameH[i], nameH[j]);
      char* yname = (char*)(&name[0]);
      CHECKED_CPX_CALL(CPXnewcols, env, lp, 1, 0, &lb, &ub, &ytype, &yname);
    }
  }

  // END OF VARIABLES DECLARATION

  // add origin contrainst
  std::vector<int> orIdx(H);
  std::vector<double> orCoef(H, 1.0);
  int orMatBeg = 0;
  char orSign = 'E';
  for (int i = 1; i < H; i++) {
    orIdx[i] = i;
  }
  const double orRhs = (double) H;
  CHECKED_CPX_CALL(CPXaddrows, env, lp, 0, 1, orIdx.size(), &orRhs, &orSign,
    &orMatBeg, &orIdx[0], &orCoef[0], NULL, NULL);

  /*// add consecutive arcs' constraints
  for (int i = 0; i < I; i++) {
    std::vector<int> idx(J);          // indexes
    std::vector<double> coef(J, 1.0); // coefficients
    char sign = 'L';                  // less or equal
    int matbeg = 0;
    for (int j = 0; j < J; j++)
    {
      idx[j] = i*J + j;
    }
    CHECKED_CPX_CALL(CPXaddrows, env, lp, 0, 1, idx.size(), &D[i], &sign, &matbeg, &idx[0], &coef[0], NULL, NULL);
  }*/

  // add out-degree constraint for holes
  for (int i = 0; i < H; i++) {
    std::vector<int> idx(H);          // indexes
    std::vector<double> coef(H, 1.0); // coefficients
    char sign = 'E';                  // less or equal
    int matbeg = 0;
    for (int j = 0; j < H; j++)
    {
      idx[j] = ystart + i*H + j;
    }
    const double rhs = 1.0;
    CHECKED_CPX_CALL(CPXaddrows, env, lp, 0, 1, idx.size(), &rhs, &sign,
        &matbeg, &idx[0], &coef[0], NULL, NULL);
  }

  // print (debug)
  CHECKED_CPX_CALL( CPXwriteprob, env, lp, "drilling.lp", NULL );
  /// status = CPXwriteprob (env, lp, "myprob", filetype_str);
}

int main (int argc, char const *argv[])
{
    try
    {
        // init
        DECL_ENV(env);
        DECL_PROB(env, lp);

        // setup LP
        setupLP(env, lp);

        // optimize
        CHECKED_CPX_CALL(CPXmipopt, env, lp);

        // print objval
        double objval = 0.0;
        CHECKED_CPX_CALL(CPXgetobjval, env, lp, &objval);
        std::cout<< "Objval: "<<objval<<std::endl;

        //print solution (var values)
        int n = CPXgetnumcols(env, lp);
        std::vector<double> varVals;
        varVals.resize(n);
        CHECKED_CPX_CALL( CPXgetx, env, lp, &varVals[0], 0, n - 1 );
            /// status = CPXgetx (env, lp, x, 0, CPXgetnumcols(env, lp)-1);
        for ( int i = 0 ; i < n ; ++i ) {
            std::cout<<"var in position "<<i<<" : "<<varVals[i]<<std::endl;
            /// to get variable name, use the RATHER TRICKY "CPXgetcolname"
            /// status = CPXgetcolname (env, lp, cur_colname,
            /// cur_colnamestore, cur_storespace, &surplus, 0, cur_numcols-1);
        }
        CHECKED_CPX_CALL( CPXsolwrite, env, lp, "drilling.sol" );
        // free
        CPXfreeprob(env, &lp);
        CPXcloseCPLEX(&env);
    }
    catch(std::exception& e)
    {
        std::cout<<">>>EXCEPTION: "<<e.what()<<std::endl;
    }
    return 0;
}
