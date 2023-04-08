/*
#include "Sym_Mat.hpp"

double& Sym_Mat::operator()(int i, int j) const{
if (j < i){
    return values[n_size*(n_size-1)/2 - (n_size-j)*(n_size-j-1)/2+i];
} else {
    return values[n_size*(n_size-1)/2 - (n_size-i)*(n_size-i-1)/2+j];
}
}
*/
