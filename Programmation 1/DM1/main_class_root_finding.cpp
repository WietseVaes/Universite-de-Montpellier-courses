
#include "class_root_finding.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { return pow(x,-1)-pow(2,x);}
//double f(double x) { return 1/(x-0.5);}
double g(double x) { return pow(2,-x)+exp(x) + 2*cos(x)-6;}
double h(double x) { return x*x*x - 5*x*x + 3*x + 7;}
double hd(double x) { return 3*x*x - 10*x + 3;}

int main(){
    root_finding root1(f, f, 0);
    double res1 = root1(0,1);
    cout << "A root of x^(-1)-2^x (using Bisection): " << res1 << endl;
    root_finding root2(g, g, 0);
    double res2 = root2(1,3);
    cout << "A root of 2^(-x)+e^x+2cos(x)-6 (using Bisection): " << res2 << endl;
    root_finding root3(h, hd, 1);
    double res3 = root3(5);
    cout << "A root of x^3-5^2+3x+7 (using Newton's): " << res3 << endl;
}

