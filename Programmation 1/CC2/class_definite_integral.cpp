//#pragma once
#include <iostream>
#include "class_definite_integral.hpp"

  definite_integral::definite_integral(double a, double b, pfn f){ // constructor
      lower = a;
      upper = b;
      integrand = f;
  }

    double definite_integral::lowbd() const { // accessor: get lower bound
      return lower;
    }

  double definite_integral::upbd() const {return upper;} // accessor: get upper bound

  void definite_integral::change_bounds(double a, double b){ //change integral bounds to a, b
      lower = a;
      upper = b;
  }

  double definite_integral::trapezoidal(int n) const{ // compute integral using trapezoidal rule

    if (n<0){
      std::cout << "Error in trapezoidal: please use a positive amount of subintervals." << std::endl;
      exit(0);
    }

    double int_sum = 0;
    double delta_x = (upper-lower)/n;
    double start_point;
    double end_point;

    for (int ii=1; ii<=n; ++ii){
       start_point = lower+(ii-1)*delta_x;
       end_point = start_point + delta_x;
       int_sum += (integrand(start_point)+integrand(end_point))*delta_x/2;
    }
    return int_sum;
  }

