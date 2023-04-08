#include <iostream>
#include <math.h>
#include "class_definite_integral.hpp"

double function_name(double d) { return d*d;}

using namespace std;

int main()
{
    definite_integral Integral(1., 6., function_name); //TEST: check
    cout << "The lower bound is: " << Integral.lowbd() << endl; //TEST: check
    cout << "The upper bound is: " << Integral.upbd() << endl; //TEST: check

    int n = 100;
    double result = Integral.trapezoidal(n);

    cout << "Integral using trapezoidal with n = "<< n << " is: " << result << endl; //TEST: check

    cout << endl; //Just to make the cmd more structured.

    Integral.change_bounds(0., 5.);

    cout << "The lower bound after a change is: " << Integral.lowbd() << endl; //TEST: check
    cout << "The upper bound after a change is: " << Integral.upbd() << endl; //TEST: check

    result = Integral.trapezoidal(n);

    cout << "Integral after change using trapezoidal with n = "<< n << " is: " << result << endl; //TEST: check

    cout << endl;

    definite_integral Integral2(0., 5., sqrt);
    result = Integral2.trapezoidal(n);

    cout << "Integral of sqrt(x) using trapezoidal with n = "<< n << " is: " << result << endl; //(extra) TEST: check
}
