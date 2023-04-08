#pragma once
#include "Abstract_Mat.hpp"
#include "Vector.hpp"

class COO_Mat: public Abstract_Mat
{
public:

    COO_Mat(int n_size, int nb_non_zero);
    ~COO_Mat();

    Vector operator*(const Vector&) const;

private:

    double* values;
    int* coord_i;
    int* coord_j;

    int number_non_zero;

};
