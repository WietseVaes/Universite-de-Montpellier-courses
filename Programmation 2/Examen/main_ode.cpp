
#include "ode.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double f(double t, double x) {
  return x*(1 - exp(t))/(1 + exp(t));
}
double sol(double t) {
    return (12*exp(t))/((1+exp(t))*(1+exp(t)));
}

int main()
{

  ode exmp(0., 3., 2., f); // x(0) = 3, T =2
  double* soln = exmp.euler(100); // 100 subintervals

  cout << "La valeur approchée de x a l'instant T est: "<< soln[99] << endl;

    double t0 = 0.; double tn = 2.; int n = 100;

    double deltat = (tn-t0)/n;
    double errinf = abs(sol(t0+deltat)-soln[0]); double err;
    for (int ii = 1; ii<n; ++ii){

        err = abs(sol(t0+(ii+1)*deltat)-soln[ii]);

        err>errinf? errinf = err:0;
    }
    cout << "Inf norm of the error is: " << errinf << endl;
}

