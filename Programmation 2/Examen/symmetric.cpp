/*
#include "symmetric.hpp"
#include <iostream>
using namespace std;

SymmetricMtx::SymmetricMtx(int n) {
    dimn = n;
    symmx = new double[dimn*(dimn+1)/2];
    for (int i=0; i<(dimn*(dimn+1)/2); i++){
        symmx[i] = 0;
    }
  }


double& SymmetricMtx::operator()(int i, int j) {
    if (i < j){
        return symmx[j*(j+1)/2+i];
    } else {
        return symmx[i*(i+1)/2+j];
    }
}
*/
