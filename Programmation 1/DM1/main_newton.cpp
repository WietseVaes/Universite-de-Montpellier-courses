
#include <iostream>
#include "newton.hpp"
#include <stdlib.h>

using namespace std;

double f(double x) { return x*x*x - 5*x*x + 3*x + 7;}
double fd(double x) { return 3*x*x - 10*x + 3;}

int main(){
    double delta = 10e-10;
    double epsilon = 10e-10;

    double c3 = newton(5, f, fd, delta, epsilon, 1000);
    cout << "Using Newton's method on f, gives: " << c3 << endl;
}

