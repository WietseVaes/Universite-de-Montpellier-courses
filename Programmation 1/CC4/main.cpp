#include <iostream>
#include "lagrange.hpp"
#include <cmath>
using namespace std;

int main()
{
int n = 4;


double vx1[n]; double vy1[n]; double x_in1 = 1.4;
for (int ii = 0; ii<n; ii++){
    vx1[ii] = 1+ii/4.; //should be n (n isn't double)
    vy1[ii] = exp(vx1[ii]);
}

double res1 = lagrange(vx1, vy1, x_in1, n);
cout << "double: Interpolated value of exp(x) in 1.4 is: " << res1 << endl;

float vx2[n]; float vy2[n]; float x_in2 = 1.4;
for (int ii = 0; ii<n; ii++){
    vx2[ii] = 1+ii/4.; //should be n (n isn't double)
    vy2[ii] = exp(vx1[ii]);
}

float res2 = lagrange(vx2, vy2, x_in2, n);
cout << "float: Interpolated value of exp(x) in 1.4 is: " << res2 << endl;
cout << "'real' value of exp(1.4): " << exp(1.4) << endl;
}
