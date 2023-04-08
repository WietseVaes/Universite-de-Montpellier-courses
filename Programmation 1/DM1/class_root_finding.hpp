#include <iostream>

using namespace std;
typedef double (*pfn) (double);

class root_finding{
private:
    pfn dfunc;
    pfn func;
    int mode;
public:
    root_finding(pfn f, pfn df = 0, int modus = 1); // 0 = Bisection, 1 = Newton;

    double operator()(double x1, double x2 = 0., double delta = 10e-7 , double epsilon = 10e-7 , int n_max = 100);
};
