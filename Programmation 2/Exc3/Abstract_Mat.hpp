#pragma once
#include "Vector.hpp"

class Abstract_Mat{

protected:
    int n_rows;
    int n_cols;

public:

    Abstract_Mat(int n_size){n_rows = n_size;n_cols = n_size;};
    virtual Vector operator*(const Vector&) const = 0;
    int nrows() const{return n_rows;}; // M.nrows();
    int ncols() const{return n_cols;};
    virtual ~Abstract_Mat(){};

    int CG(Vector& x, const Vector& b, double& eps, int& iter, int prec);
};
