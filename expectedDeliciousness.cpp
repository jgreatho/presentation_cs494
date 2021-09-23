#include <iostream>
#include <map>
#include <iterator>
#include <utility>
#include <math.h>
using namespace std;
#define cc const unsigned char
#define uc unsigned char
#define ui unsigned int

ui keyGen(ui p, ui b) {
  return (p*b) + (2*p / (b+1)) + p + b;
}

double expectedVal(uc p, uc b, map<ui, double> *Eptr,
                   int d[], cc N) {
  uc i;
  double delish;
  ui key;
  pair<ui, double> temp;
  map<ui, double>::iterator nit; 

  // Error Checking
  if(N <= b || N < 1 || p > N) {
    cerr << "Encountered b (bigger selected) >= N (total panackes).\n";
    return -1.0;
  }

  // Calculate Current Key Value
  key = keyGen((ui)p,(ui)b);

  // Check if Current Values are Stored
  nit = Eptr->find(key);
  if(nit == Eptr->end() ) {

    // Not Stored: Calcualte All Current Pancake Expected Values
    if(p == 0) delish = (double) d[p];
    else delish = (1 / (double)(N-p-b)) * (double) d[p];
    temp = make_pair(key, delish);
    Eptr->insert(temp);

  // Stored: Retrieve Current Pancake Expected Values
  } else delish = nit->second;

  // Calculate All Smaller Potential Deliciousnesses Values
  for(i = 0; i < p; i++) {
    // Sum Smaller Pancake Expected Values
    delish += (1 / (double)p) * expectedVal(i,b+1,Eptr,d,N);
  }
  return delish;
}

double expectedDeliciousness(int d[251]) {
  uc i, N = 0;
  double delish = 0.0;
  map<ui, double> E;
  map<ui, double>::iterator nit;

  // Find Array Size
  while(d[N] != 0 && N < 251) N++;

  for(i = 0; i < N; i++) {
    // Sum Deliciousness Probablilites
    delish += expectedVal(i,0,&E,d,N);
  }
  return delish / (double)N;
}
