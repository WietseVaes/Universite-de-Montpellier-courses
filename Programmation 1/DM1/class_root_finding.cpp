#include "class_root_finding.hpp"
#include "newton.hpp"
#include "bisection.hpp"
#include <iostream>


root_finding::root_finding( pfn f, pfn df, int modus){
func = f;
dfunc = df;
mode = modus;
}

double root_finding::operator()(double x1, double x2, double delta, double epsilon, int n_max){
if (mode == 0){
    return bisection( x1, x2, func, delta, epsilon);
} else if (mode == 1){
    return newton(x1, func, dfunc, delta, epsilon, n_max);
} else {
    cerr << "invalid mode" <<endl;
    exit(0);
}
}
