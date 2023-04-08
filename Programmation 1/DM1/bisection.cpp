#pragma once
#include "bisection.hpp"
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

double bisection( double a, double b, double(*f)(double), double delta, double epsilon){
if (f(a)*f(b)>0){
    cerr << "error in bisection: bisection method can not be used with given a and b." << endl;
    exit(0);
}
double c = (a+b)/2;
if (isinf(f(c))){
    cerr << "error in bisection: devision by 0" << endl;
    exit(0);
}
if (f(a)*f(c)<0){
    if (abs(b-a)<delta || abs(f(c))<epsilon){
        return c;
    } else {
        return bisection(a, c, f, delta, epsilon);
    }
} else {
    if (abs(b-a)<delta || abs(f(c))<epsilon){
        return c;
    } else {
        return bisection(c, b, f, delta, epsilon);
    }
}
}
