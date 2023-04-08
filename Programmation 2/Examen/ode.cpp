#include "ode.hpp"

ode::ode(double tini, double xini, double tend, double (*f)(double, double))
{
t_ini = tini;
x_0 = xini;
t_end = tend;
sfn = f;
}

double* ode::euler(int n) const
{
    double* res = new double[n];
    double deltat = (t_end-t_ini)/n;

    res[0] = x_0 + deltat*sfn(t_ini,x_0);
    for (int ii = 1; ii < n; ++ii){
        res[ii] = res[ii-1] + deltat*sfn(t_ini+ii*deltat,res[ii-1]);
    }

    return res;
}
