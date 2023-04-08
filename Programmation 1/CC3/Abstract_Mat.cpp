#include "Abstract_Mat.hpp"
#include "Vector.hpp"


int Abstract_Mat::CG(Vector& x, const Vector& b, double& eps, int& iter, int prec){

  if (n_rows != b.size()){
    cout << "CG: matrix and vector sizes do not match" << endl;
  }

  const int maxiter = iter;

  Vector r = b - (*this)*x;
  //Vector z = preconding(r,prec);
  Vector z = r;
  Vector p = z;
  double zr = dot(z,r);
  const double stp = eps*b.twonorm();

  if (r.maxnorm() == 0.0) {
    eps = 0.0;
    iter = 0;
    return 0;
  }

  for (iter = 0; iter < maxiter; iter++) {
    Vector mp = (*this)*p;
    double pap = dot(mp,p);
    double alpha = zr/pap;
    x += alpha*p;
    r -= alpha*mp;
    if (r.twonorm() <= stp) break;
    //z = preconding(r,prec);
	z=r;
    double zrold = zr;
    zr = dot(z,r);
    double beta= zr/zrold;
    p = z + beta*p;
  }
  eps = r.twonorm();
  if (iter == maxiter) return 1;
  else return 0;

} // end CG()

