#pragma once
#include "Vector.hpp"

template<typename T>
class Abstract_Mat{
protected:
    int n_rows;
    int n_cols;

public:

    Abstract_Mat(int n_size){n_rows = n_size;n_cols = n_size;};
    virtual Vector<T> operator*(const Vector<T>&) const = 0;
    int nrows() const{return n_rows;}; // M.nrows();
    int ncols() const{return n_cols;};
    virtual ~Abstract_Mat(){};

    int CG(Vector<T>& x, const Vector<T>& b, T& eps, int& iter, int prec);
};

template<typename T>
int Abstract_Mat<T>::CG(Vector<T>& x, const Vector<T>& b, T& eps, int& iter, int prec){

  if (n_rows != b.size()){
    cout << "CG: matrix and vector sizes do not match" << endl;
  }

  const int maxiter = iter;

  Vector<T> r = b - (*this)*x;
  //Vector z = preconding(r,prec);
  Vector<T> z = r;
  Vector<T> p = z;
  T zr = dot(z,r);
  const T stp = eps*b.twonorm();

  if (r.maxnorm() == 0.0) {
    eps = 0.0;
    iter = 0;
    return 0;
  }

  for (iter = 0; iter < maxiter; iter++) {
    Vector<T> mp = (*this)*p;
    T pap = dot(mp,p);
    T alpha = zr/pap;
    x += alpha*p;
    r -= alpha*mp;
    if (r.twonorm() <= stp) break;
    //z = preconding(r,prec);
	z=r;
    T zrold = zr;
    zr = dot(z,r);
    T beta= zr/zrold;
    p = z + beta*p;
  }
  eps = r.twonorm();
  if (iter == maxiter) return 1;
  else return 0;

} // end CG()


