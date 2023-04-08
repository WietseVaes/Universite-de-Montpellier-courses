#include <iostream>
#include <cmath>

using namespace std;

typedef double AD[3];

double normRow(AD* v , int const &j )
{
double norm_r_sum = 0;
for (int i=0; i<3; ++i){
    norm_r_sum += v[j][i]*v[j][i];
}
return sqrt(norm_r_sum);
}
