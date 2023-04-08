#include <iostream>
#include <cmath>
#include "quadraticRoot.hpp"
#include "normRow.hpp"
#include "maxRow.hpp"

using namespace std;

typedef double AD[3];

int main()
{

cout << "Coefficients of a quadratic function: ";
double a;
double b;
double c;
cin >> a >> b >> c;
pair<double , double> roots = quadraticRoot(a, b, c);


double A[][3] = {{2, 9, 4},{8, 7, 10}, {1, 2, 3}};

int j = 0;
double norm1 = normRow(A , j);
cout << "The Euclidic norm of row " << j+1 <<" of A is: " << norm1 <<endl;

j = 1;
double norm2 = maxRow(A, j);
cout << "The inf norm of row "<< j+1 <<" of A is: " << norm2 <<endl;
}
