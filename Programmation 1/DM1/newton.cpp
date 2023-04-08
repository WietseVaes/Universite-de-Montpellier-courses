#include "newton.hpp"
#include <cmath>

using namespace std;

double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int n_max){

if (n_max == 0 || abs(f(xp))<epsilon){
    return xp;
} else {
	double newxp = xp - f(xp)/fd(xp);
	if (abs(xp-newxp) < delta) {
		return newxp;
	} else {
    		return newton(newxp, f, fd, delta, epsilon, n_max-1);
	}
}

}
