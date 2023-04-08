
#pragma once
#include "Abstract_Mat.hpp"
#include "Vector.hpp"

template<typename T>
class COO_Mat: public Abstract_Mat<T>{
public:

    COO_Mat(int n_size, int nb_non_zero);
    ~COO_Mat();

    Vector<T> operator*(const Vector<T>&) const;

    T* values;
    int* coord_i;
    int* coord_j;

    int number_non_zero;
private:
};
template<typename T>
COO_Mat<T>::COO_Mat(int n_size, int nb_non_zero): Abstract_Mat<T>(n_size),number_non_zero(nb_non_zero){

    int n_cols = this->n_cols;
    int n_rows = this->n_rows;

values = new T[nb_non_zero];
coord_i = new int[nb_non_zero];
coord_j = new int[nb_non_zero];
}

template<typename T>
COO_Mat<T>::~COO_Mat(){
delete [] values;
delete [] coord_i;
delete [] coord_j;
}

template<typename T>
Vector<T> COO_Mat<T>::operator*(const Vector<T>& v) const{
    int n_cols = this->n_cols;
    int n_rows = this->n_rows;
if(v.size() == n_cols){
   Vector<T> result(n_rows);
   for (int i_coeff = 0; i_coeff<number_non_zero; ++i_coeff){
    int i_rows = coord_i[i_coeff];
    int i_cols = coord_j[i_coeff];
    result[i_rows] += values[i_coeff]*v[i_cols];
   }
   return result;
} else{
    cout << "Error in Operator*: bad matrix/vector sizes" << endl;
    exit(0);
}

}

