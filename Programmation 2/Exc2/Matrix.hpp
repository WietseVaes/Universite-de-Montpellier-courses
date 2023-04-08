#pragma once
#include <iostream>
#include "Vector.hpp"

class Vector;

using namespace std;

class Matrix{

public:

    Matrix(int n, double value = 0.);

    Matrix(Matrix const & );

    Matrix& operator=(const Matrix&);

    ~Matrix();

    void Print();

    int nrows() const{return n_rows;};
    int ncols() const{return n_cols;};

    double* operator[](int i) const{
        return values[i]; // kunnen hier ook door maken dat we vanaf 1 beginnen
    }

    friend Matrix operator *(Matrix & M1, Matrix & M2);

    Vector operator*(const Vector&) const; //Matrix-vector multiply

    friend ostream& operator<<(ostream&,const Matrix&);

    int CG(Vector& x, const Vector& b, double& eps, int& iter, int prec);

private:
    int n_rows;
    int n_cols;
    double** values;
};
