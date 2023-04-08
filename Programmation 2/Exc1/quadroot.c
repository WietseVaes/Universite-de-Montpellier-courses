#include <iostream>
#include <cmath>

using namespace std;

pair<double , double> quadraticRoot (const double & a, const double & b, const double & c){
    double D = b*b-4*a*c;

    if (D > 0){
        roots = {(-b-sqrt(D))/(2*a),(-b+sqrt(D))/(2*a)};
        return roots;
    } else if (D==0){
        roots = {(-b)/(2*a),(-b)/(2*a)};
    return roots;
    } else {
        cout << "Error: There are no real roots." << endl;
    return 0;
    }
}
