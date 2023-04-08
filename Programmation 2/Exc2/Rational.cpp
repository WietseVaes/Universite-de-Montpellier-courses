#include "Rational.hpp"

 void Rational::set(int num,int den)
 {
     M_d = den;
     M_n = num;
 }
 int Rational::den()const {return M_d;}
 int Rational::num()const {return M_n;}

