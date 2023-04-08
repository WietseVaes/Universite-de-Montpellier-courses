
#include <iostream>
#include "Vector.hpp"
using namespace std;

Vector::Vector(int size_n, double value):M_size(size_n){
   M_data = new double[M_size];

   //cout << "Constructeur Vector: allocation du tableau: " << M_data << endl;

   for(int kk=0; kk<M_size; ++kk){
    M_data[kk]=value;
   }
}

Vector::Vector(Vector const & v){
    v.M_size == 0? M_data = nullptr : M_data = new double[v.M_size];

    M_size = v.M_size;
    //cout << endl;
    //cout << "Copy constructeur: allocatio du vecteur: " << M_data << " de taille " << M_size << endl;
    //cout << endl;

    for(int kk=0; kk<M_size; ++kk){
        M_data[kk]=v.M_data[kk];
    }
}

Vector::~Vector(){
//cout << "Destruction du vecteur: " << M_data<< "\n";
delete[] M_data;
}

void Vector::Print(){
    //cout << "les composantes du vecteur sont: " << endl;
    //cout << " " << endl;
    for (int ii=0;ii<M_size;ii++){
        cout << "v["<< ii+1<<"] =" <<" " << M_data[ii] << endl;
    }
    //cout << endl;
}

Vector& Vector::operator=(Vector const & v){
    if (this != &v){
        delete[] M_data;
        M_data = new double[M_size=v.M_size];
        //cout << "Assign du vecteur: " << v.M_data << "\n";
           for(int kk=0; kk<M_size; ++kk) M_data[kk]=v.M_data[kk];
    }
    return *this;
}

double& Vector::operator[](int i){
    return M_data[i];
}

std::ostream & operator << (std::ostream& s, const Vector& v){
    using std::endl;
    //s << "Surcharge opérateur: taille du vecteur: " << v.M_size << endl;
    for(int i=0; i<v.M_size; i++){
        s << "v[" << i+1 << "]: " << v[i] << endl;
    }
    return s;
}


Vector operator +(const Vector & v){
    Vector vv = v;
    return vv;
}

Vector operator -(const Vector & v){
    Vector tmp(v.size());
    for (int ii = 0; ii<v.size(); ++ii){
        tmp[ii] = -1*v[ii];
    }
    return tmp;
}

Vector operator +(const Vector & v1, const Vector & v2){
    Vector tmp(v1.size());
    if (v1.size()!=v2.size()){
        cerr << "error in operator+: Vectors do not have the same length." << endl;
        exit(0);
    } else {
        for (int ii = 0; ii<v1.size(); ++ii){
            tmp[ii] = v1[ii]+v2[ii];
        }
    }
    return tmp;
}
Vector operator -(const Vector & v1, const Vector & v2){
    Vector tmp(v1.size());
    if (v1.size()!=v2.size()){
        cerr << "error in operator-: Vectors do not have the same length." << endl;
        exit(0);
    } else{
        for (int ii = 0; ii<v1.size(); ++ii){
            tmp[ii] = v1[ii]-v2[ii];
        }
    }
    return tmp;
}

Vector operator *(double const lambda, Vector & v){
    Vector tmp(v.size());
        for (int ii = 0; ii<v.size(); ++ii){
            tmp[ii] = lambda*v[ii];
        }
    return tmp;
}

Vector operator *(Vector & v, double const lambda){
    Vector tmp(v.size());
        for (int ii = 0; ii<v.size(); ++ii){
            tmp[ii] = v[ii]*lambda;
        }
    return tmp;
}

Vector& Vector::operator +=(Vector const & v){
    if (M_size == v.size()) {
    for(int kk=0; kk<M_size; ++kk)  M_data[kk] += v[kk];
    return *this;
    } else {
    cerr << "error in operator+=: vector's are not of the same size." << endl;
    exit(0);
    }
}
//Twee mogelijke manieren.
Vector operator -=(Vector & v1, Vector const & v){
    if (v1.size() == v.size()) {
    for(int kk=0; kk<v1.size(); ++kk) v1[kk] -= v[kk];
    } else {
    cerr << "error in operator-=: vector's are not of the same size." << endl;
    exit(0);
    }
    return v1;
}
double Vector::maxnorm() const{
    double maxi = M_data[0];
    for (int ii = 1; ii < M_size; ++ii){
           maxi = maxi>M_data[ii]? maxi:M_data[ii];
    }
    return maxi;
}

double Vector::twonorm() const{
        double nm = pow(abs(M_data[0]),2);
        for (int ii = 1; ii < M_size; ii++){
            nm += abs(M_data[ii])*abs(M_data[ii]);
        }
        double res = sqrt(nm);
        return res;
    }

double dot(const Vector& v1, const Vector& v2){
    double dot_sum = v1[0]*v2[0];
    if (v1.size() == v2.size()) {
    for(int kk=1; kk<v1.size(); ++kk)  dot_sum +=  v1[kk]*v2[kk];
    } else {
    cerr << "error in dot: vector's are not of the same size." << endl;
    exit(0);
    }
    return dot_sum;
}

