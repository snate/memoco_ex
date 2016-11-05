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
#include <fstream>
#include <sstream>
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

const int NAME_SIZE = 512;
char name[NAME_SIZE];

double* generateCosts() {
  double* data = new double[H*H];
  ifstream input("data");
  string line;
  int lineNumber = 0;
  while(lineNumber < H && getline(input, line)) {
    istringstream ss(line);
    string name;
    ss>>name;
    for (int i = 0; i < H; i++)
      ss>>data[lineNumber*H+i];
    lineNumber++;
  }
  return data;
}

double* stubWithPitagorianCosts() {
  double stackArr[H*H] = { 0.0, 3.0, 5.0,
      3.0, 0.0, 4.0,
      5.0, 4.0, 0.0 };
  double* heapArr = new double[H*H];
  for (int i = 0; i < H*H; i++)
    heapArr[i] = stackArr[i];
  return heapArr;
}

void setupLP(CEnv env, Prob lp) {

  double* C = generateCosts(); // distances between holes

  vector<vector<int> > map_x;
  map_x.resize(H);
  for (int i = 0; i < H; i++)
    map_x[i].resize(H);
  vector<vector<int> > map_y;
  map_y.resize(H);
  for (int i = 0; i < H; i++)
    map_y[i].resize(H);
  int var_count = 0;

  // add x_{i,j} positive integer variables
  for (int i = 0; i < H; i++)
    for (int j = 0; j < H; j++) {
      char xtype = 'I';
      double lb = 0.0;
      double ub = CPX_INFBOUND;
      snprintf(name, NAME_SIZE, "x_%c,%c", nameH[i], nameH[j]);
      char* xname = (char*)(&name[0]);
      CHECKED_CPX_CALL(CPXnewcols, env, lp, 1, 0, &lb, &ub, &xtype,
          &xname);
      map_x[i][j] = var_count++;
      // status = CPXnewcols (env, lp, ccnt, obj, lb, ub, xctype, colname);
    }

  // add y_{i,j} boolean variables
  for (int i = 0; i < H; i++)
    for (int j = 0; j < H; j++) {
      char ytype = 'B';
      double lb = 0.0;
      double ub = 1.0;
      snprintf(name, NAME_SIZE, "y_%c,%c", nameH[i], nameH[j]);
      char* yname = (char*)(&name[0]);
      CHECKED_CPX_CALL(CPXnewcols, env, lp, 1, &C[i*H+j], &lb, &ub, &ytype, &yname);
      map_y[i][j] = var_count++;
    }

  // END OF VARIABLES DECLARATION

  // add origin contrainst
  vector<int> orIdx(H);
  vector<double> orCoef(H, 1.0);
  int orMatBeg = 0;
  char orSign = 'E';
  for (int i = 0; i < H; i++)
    orIdx[i] = map_x[0][i];
  const double orRhs = (double) H;
  CHECKED_CPX_CALL(CPXaddrows, env, lp, 0, 1, orIdx.size(), &orRhs, &orSign,
    &orMatBeg, &orIdx[0], &orCoef[0], NULL, NULL);

  // add consecutive arcs' constraints
  for (int k = 1; k < H; k++) {
    vector<int> idx(2*H-2);      // indexes
    vector<double> coef(2*H-2); // coefficients
    for (int i = 0; i < H-1; i++) {
      coef[i] = 1.0;
      coef[H-1+i] = -1.0;
    }
    char sign = 'E';                  // equal
    int matbeg = 0;
    int count = 0;
    for (int j = 0; j < k; j++) {
      idx[count]     = map_x[j][k];
      idx[H-1+count] = map_x[k][j];
      count++;
    }
    for (int j = k+1; j < H; j++) {
      idx[count]     = map_x[j][k];
      idx[H-1+count] = map_x[k][j];
      count++;
    }
    const double rhs = 1.0;
    CHECKED_CPX_CALL(CPXaddrows, env, lp, 0, 1, idx.size(), &rhs, &sign,
        &matbeg, &idx[0], &coef[0], NULL, NULL);
  }

  // add out-degree constraint for holes
  for (int i = 0; i < H; i++) {
    vector<int> idx(H);          // indexes
    vector<double> coef(H, 1.0); // coefficients
    char sign = 'E';                  // equal
    int matbeg = 0;
    for (int j = 0; j < H; j++)
      idx[j] = map_y[i][j];
    const double rhs = 1.0;
    CHECKED_CPX_CALL(CPXaddrows, env, lp, 0, 1, idx.size(), &rhs, &sign,
        &matbeg, &idx[0], &coef[0], NULL, NULL);
  }

  // add in-degree constraint for holes
  for (int i = 0; i < H; i++) {
    vector<int> idx(H);          // indexes
    vector<double> coef(H, 1.0); // coefficients
    char sign = 'E';                  // equal
    int matbeg = 0;
    for (int j = 0; j < H; j++)
      idx[j] = map_y[j][i];
    const double rhs = 1.0;
    CHECKED_CPX_CALL(CPXaddrows, env, lp, 0, 1, idx.size(), &rhs, &sign,
        &matbeg, &idx[0], &coef[0], NULL, NULL);
  }

  // add big-M constraint for x's and y's
  for (int i = 0; i < H; i++)
    for (int j = 0; j < H; j++) {
      vector<int> idx(2);     // indexes
      idx[0] = map_x[i][j];
      idx[1] = map_y[i][j];
      vector<double> coef(2); // coefficients
      coef[0] = 1.0;
      coef[1] = -H;
      char sign = 'L';        // less or equal
      int matbeg = 0;
      const double rhs = 0.0;
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

    // print objective function value
    double objval = 0.0;
    CHECKED_CPX_CALL(CPXgetobjval, env, lp, &objval);
    cout<< "Objval: "<<objval<<endl;

    //print solution (var values)
    int n = CPXgetnumcols(env, lp);
    vector<double> varValues;
    varValues.resize(n);
    CHECKED_CPX_CALL( CPXgetx, env, lp, &varValues[0], 0, n - 1 );
    for(int i = 0 ; i < H*H; ++i)
      cout<<"x #"<<i+1<<": "<<varValues[i]<<endl;
    for(int i = 0 ; i < H*H; ++i)
      cout<<"y #"<<i+1<<": "<<varValues[H+i]<<endl;
    CHECKED_CPX_CALL( CPXsolwrite, env, lp, "drilling.sol" );
    // free
    CPXfreeprob(env, &lp);
    CPXcloseCPLEX(&env);
  }
  catch(exception& e)
  {
      cout<<">>>EXCEPTION: "<<e.what()<<endl;
  }
  return 0;
}
