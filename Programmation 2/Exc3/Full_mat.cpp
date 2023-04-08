
#include <iostream>
#include <cmath>
#include "Full_mat.hpp"

using namespace std;

Full_mat::Full_mat(int n_size, double value): Abstract_Mat(n_size){
    values = new double*[n_size];
    for (int ii = 0; ii<n_size; ++ii){
        values[ii] = new double[n_size];
    }
    for (int ii = 0; ii<n_size; ++ii){
        for(int jj = 0; jj<n_size; ++jj){
          values[ii][jj] = value;
        }
    }
}

Full_mat::Full_mat(Full_mat const & M) : Abstract_Mat(M.n_rows)
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

Full_mat::~Full_mat(){
    //cout << "Destruction du Matrix: " << values << "\n";
    for (int ii = 0; ii<n_rows; ++ii){
        delete [] values[ii];
    }
    delete [] values;
}

void Full_mat::Print(){
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


Full_mat operator*(Full_mat & M1, Full_mat &M2){
    Full_mat tmp(M1.nrows());
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


Full_mat& Full_mat::operator=(const Full_mat& M){
    if (&M == this){
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

Vector Full_mat::operator*(const Vector& v) const{

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


ostream & operator << (ostream& s, const Full_mat& M){
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
