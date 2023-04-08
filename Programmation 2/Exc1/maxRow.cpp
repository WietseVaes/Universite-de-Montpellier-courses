#include <iostream>

using namespace std;

double maxRow(double v[][3], int const &j){
    double maxi = v[j][0];
    double b;
    for (int i=0; i<3; ++i){
        b = v[j][i];
        maxi = maxi>b? maxi:b;
    }
    return maxi;
}
