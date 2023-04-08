#pragma once
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

class Vector{
private:

    double* M_data;
    int M_size;

public:

    Vector(int size_n, double value=0); // constructor
    Vector(Vector const & v);
    ~Vector(); // destructor
    void Print();

    Vector& operator =(Vector const & v);

    double& operator[](int i);

    double operator[](int i) const{
    return M_data[i]; // kunnen hier ook door maken dat we vanaf 1 beginnen
    }

    int size() const{return M_size;} // zet enkel hier, gebruik met v.size

    // Kan dienen voor te printen, ma we hebben al print

    friend std::ostream & operator << (std::ostream&, const Vector&);


    friend Vector  operator+(const Vector & v);
    friend Vector  operator-(const Vector & v);

    friend Vector operator +(const Vector & v1, const Vector & v2);
    friend Vector operator -(const Vector & v1, const Vector & v2);

    friend Vector operator *(double const lambda, Vector & v);
    friend Vector operator *(Vector & v, double const lambda);

    Vector& operator +=(Vector const & v);
    friend Vector operator -=(Vector & v1, Vector const & v);

    double maxnorm() const;
    double twonorm() const;



    friend double dot(const Vector&, const Vector&);

};

