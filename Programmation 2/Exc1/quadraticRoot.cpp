#include <iostream>
#include <cmath>

using namespace std;

pair<double , double> quadraticRoot (const double & a, const double & b, const double & c){
    double Discri = b*b-4*a*c;
    pair<double , double > roots;
    if (a == 0){
        roots = make_pair(-c/b,-c/b);
        cout << "The only root is: "<< roots.first << endl;
        return roots;
    } else if (Discri > 0.0){
        double x1 = (-b-sqrt(Discri))/(2*a);
        double x2 = (-b+sqrt(Discri))/(2*a);
        roots = make_pair(x1,x2);
        cout << "The roots are: "<< roots.first << " and " << roots.second << endl;
    } else if (Discri==0){
        roots = {(-b)/(2*a),(-b)/(2*a)};
        cout << "The only root is: "<< roots.first << endl;
    } else {
        cerr << "Error: There are no real roots." << endl;
        abort;
    }
    return roots;
}
