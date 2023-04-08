#include <iostream>
#include "Vector.hpp"
#include "Full_mat.hpp"
#include "Abstract_Mat.hpp"
#include "COO_mat.hpp"
#include <cmath>

using namespace std;

int main()
{
int n=20; int m = 20;

//Full_mat mat1(n);
/*
for (int i=0; i<n; i++){
    for (int j=0; j<m;j++){
        mat1[i][j] = n/(abs(i-j)+1.0);
    }
}

Vector vec1(n);
for (int i = 0; i<n;i++) vec1[i] = i;

int iter = 200;
double eps = 1.0e-14;
Vector res(vec1.size());

Abstract_Mat* ptm = &mat1;

int ret = ptm->CG(res, vec1, eps, iter,0);

if (ret == 0) cout << "CG returned succesfully" << endl;

cout<< iter << " iterations used. " << endl;
cout << "Residual in CG = " << eps << endl;
cout << mat1*res<< endl;
*/

COO_Mat mat2(n, n*m);

int compteur = 0;
for (int i=0; i<n; i++){
    for (int j=0; j<m;j++){
        mat2.values[compteur] = n/(abs(i-j)+1.0);
        mat2.coord_i[compteur] = i;
        mat2.coord_j[compteur] = j;
        ++compteur;
    }
}





}
