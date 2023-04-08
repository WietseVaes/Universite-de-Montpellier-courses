#include <iostream>
#include <cmath>

#include "Matrix.hpp"

using namespace std;

Matrix::Matrix(int n_size, double value):n_rows(n_size), n_cols(n_size){
    values = new double*[n_cols];
    for (int ii = 0; ii<n_cols; ++ii){
        values[ii] = new double[n_rows];
    }
    for (int ii = 0; ii<n_rows; ++ii){
        for(int jj = 0; jj<n_cols; ++jj){
          values[ii][jj] = value;
        }
    }
}

Matrix::Matrix(Matrix const & M)
{
    if(M.values == 0){
    values = nullptr;
    } else {
        n_rows = M.n_rows;
        n_cols = M.n_cols;

        values = new double*[n_cols];
        for (int ii = 0; ii<n_cols; ++ii){
            values[ii] = new double[n_rows];
        }
        for (int ii = 0; ii<n_rows; ++ii){
            for(int jj = 0; jj<n_cols; ++jj){
            values[ii][jj] = M[ii][jj];
            }
        }
    }
}

Matrix::~Matrix(){
    //cout << "Destruction du Matrix: " << values << "\n";
    for (int ii = 0; ii<n_cols; ++ii){
        delete [] values[ii];
    }
    delete [] values;
}

void Matrix::Print(){
    cout << "les composantes du Matrix sont: " << endl;
    for (int ii = 0; ii<n_rows; ++ii){
        cout << "M[" << ii << "] = ";
        for(int jj = 0; jj<n_cols; ++jj){
          cout << values[ii][jj] << " ";
        }
        cout << endl;
    }
    cout << endl; // voor de schoonheid.
}


Matrix operator*(Matrix & M1, Matrix &M2){
    Matrix tmp(M1.nrows());
    if (M1.ncols()==M2.nrows()){
        for(int i_row=0;i_row<M1.nrows(); ++ i_row){
            for(int i_col=0;i_col<M2.ncols(); ++ i_col){
                  for(int jj =0;jj<M1.ncols(); ++ jj){
                    tmp[i_row][i_col] += M1[i_row][jj]*M2[jj][i_col];
                  }
            }
        }
    }
    return tmp;
}


Matrix& Matrix::operator=(const Matrix& M){
    if (&M == 0){
            return *this;
    }else{

        for (int ii = 0; ii<n_cols; ++ii){
            delete [] values[ii];
        }
        delete [] values;

        n_cols = M.n_cols;
        n_rows = M.n_rows;

        values = new double*[n_cols];
        for (int ii = 0; ii<n_cols; ++ii){
            values[ii] = new double[n_rows];
        }

        for (int ii = 0; ii<n_rows; ++ii){
            for(int jj = 0; jj<n_cols; ++jj){
            values[ii][jj] = M[ii][jj];
            }
        }

    }

    return *this;
}

Vector Matrix::operator*(const Vector& v) const{

    Vector tmp(n_rows);
    if (v.size()!=n_rows){
        cerr << "Error in operator*: vector and matrix are not compatible." <<endl;
        exit(0);
    } else {
        for (int ii = 0; ii < n_rows; ++ii){
            for (int jj = 0; jj < n_cols; ++jj){
                tmp[ii] += values[ii][jj]*v[jj];
            }
        }
    }
    return tmp;
}


ostream & operator << (ostream& s,const Matrix& M){
    using std::endl;
    for(int ii=0; ii<M.nrows(); ii++){
        if (ii>=9){
                s << "row " << ii+1 << ": " << M[ii][0] << " ";
        }else {
                s << "row " << ii+1 << ":  " << M[ii][0] << " ";
        }
        for (int jj = 1; jj<M.ncols(); ++jj){
            s << M[ii][jj] << " ";
            if (jj%83 == 81){
                s << "\n        "; //Gewoon zoda het nie te groot is.
            }
        }
        s << endl;
    }
    return s;
}


int Matrix::CG(Vector& x, const Vector& b, double& eps, int& iter, int prec){
// Conjugate gradient method.
// x: on entry, initial guess; on retrun: approximate solution
// b: right hand side vector as in A x = b;
// eps:  on entry, tolerance; on retrun: absolute residual in Euclid norm
// iter: on entry, max number of iterations allowed;
//       on return, actual number of iterations used
// prec= 0 if no preconditioning, 1 if diag prec, 2 if SSOR prec

  if (n_rows != b.size()){
    cout << "CG: matrix and vector sizes do not match" << endl;
  }

  const int maxiter = iter;

  Vector r = b - (*this)*x;                   // initial residual
  //Vector z = preconding(r,prec);            // solve the precond system
  Vector z = r;
  Vector p = z;                               // p: search direction
  double zr = dot(z,r);                       // inner prod of z and r
  const double stp = eps*b.twonorm();         // stopping criterion

  if (r.maxnorm() == 0.0) {                   // if intial guess is true soln,
    eps = 0.0;                                // return. Otherwise division by
    iter = 0;                                 // zero would occur.
    return 0;
  }

  for (iter = 0; iter < maxiter; iter++) {     // main loop of CG method
    Vector mp = (*this)*p;                     // one matrix-vector multiply
    double pap = dot(mp,p);                         // one of two inner products
    double alpha = zr/pap;                          // pap is 0 only when r is 0
    x += alpha*p;                              // update the iterative soln
    r -= alpha*mp;                             // update residual
    if (r.twonorm() <= stp) break;             // stop if convergence achieved
    //z = preconding(r,prec);                    // preconditioning
	z=r;
    double zrold = zr;
    zr = dot(z,r);                             // another of two inner products
    double beta= zr/zrold;                          // zrold = 0 only when r is 0
    p = z + beta*p;                            // update search direction
  }
  eps = r.twonorm();
    //cout <<eps<< " " << iter << endl;
  if (iter == maxiter) return 1;
  else return 0;

} // end CG()


