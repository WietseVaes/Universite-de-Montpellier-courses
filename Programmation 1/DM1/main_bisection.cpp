
#include <iostream>
#include <cmath>
#include "bisection.hpp"
#include <stdlib.h>

using namespace std;

double f(double x) { return pow(x,-1)-pow(2,x);}
//double f(double x) { return 1/(x-0.5);}
double g(double x) { return pow(2,-x)+exp(x) + 2*cos(x)-6;}
int main()
{
    double a = 0;
    double b = 1;
    double delta = 10e-7;
    double epsilon = 10e-7;
    double c1 = bisection(a, b, f, delta, epsilon);
    cout << "Using bisection on f, gives: " << c1 << endl;
    a = 1;
    b = 3;
    double c2 = bisection(a, b, g, delta, epsilon);
    cout << "Using bisection on g, gives: " << c2 << endl;

}

