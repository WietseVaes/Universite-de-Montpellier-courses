#pragma once
#include <iostream>
#include "Vector.hpp"
#include "Abstract_Mat.hpp"

class Vector;

using namespace std;

class Full_mat : public Abstract_Mat
{

public:

    Full_mat(int n, double value = 0.);

    Full_mat(Full_mat const & );

    Full_mat& operator=(const Full_mat&);

    ~Full_mat();

    void Print();

    double* operator[](int i) const{
        return values[i]; // kunnen hier ook door maken dat we vanaf 1 beginnen
    }

    friend Full_mat operator *(Full_mat & M1, Full_mat & M2);

    Vector operator*(const Vector&) const; //Matrix-vector multiply

    friend ostream& operator<<(ostream&,const Full_mat&);

private:
    int n_rows;
    int n_cols;
    double** values;
};
