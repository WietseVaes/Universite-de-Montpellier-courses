#include <iostream>
//LES 1
#include "Rational.hpp"
#include "Rational2.hpp"
//LES 2
#include "Vector.hpp"
//LES 3
#include "Matrix.hpp"
#include <cmath>

using namespace std;

int main()
{
    /*
//LES1
Rational a;
int m = 1;
int n = 7;
a.set(m,n);

Rational2 p(1,3);
Rational2 q(93);

Rational2 r;

Rational2 pp(p);

Rational2 qq(3);
qq = q; // We kunnen de operator = veranderen

//qq = qq;
Rational2 s = -qq;

cout << "denominator of a: " << a.den() << endl;
cout << "denominator of p: " << p.den() << endl;
cout << "denominator of pp: " << pp.den() << endl;
cout << "denominator of q: " << q.den() << endl;
cout << "numerator of qq: " << qq.num() << endl;
cout << "numerator of s: " << s.num() << endl;
cout << "numerator of r: " << r.num() << endl;
*/

/*
//LES 2
Vector v1(3,4);
//v1.Print();

// scope local (pour voir que la destructation est ans une scope)
{
   Vector v2(5,5);
   v2.Print();
}
//v2.Print(); Il ne marche pas. duh

Vector v2(v1);
//v2.Print();

int size_n = 10;
Vector v3(size_n);
//v3.Print();

Vector v4(2,3);
//cout << "Avant le changement:\n";
//v4.Print();
v4 = v3;
//cout << "Apres le changement:\n";
//v4.Print();

v1 = -v1;
v1.Print();

Vector v5(6,1);
Vector v6(6,4);
Vector v7(5,0);
Vector v8(10);
v8 = v5-v6;
Vector v9 = v5+v6;
//Vector v42 = v7-v6; //Gaat niet, program stopt.
//v8.Print();
//v9.Print();
Vector v10(4,1);
Vector v11 = 3*v10;
Vector v12 = v10*4;
//v11.Print();
//v12.Print();
v10 += v11;
v10.Print();
v12 -= v11;
v12.Print();

double twonorm = v12.twonorm();
cout << "Maxnorm of v12: "<< v12.maxnorm() << endl << "Twonorm of v12: " << twonorm << endl;
double dot_product = dot(v12,v10*4);
cout << "Dot product of v12 and v10 is: " << dot_product << endl;
*/

//LES 3

/*
Matrix M(4,9.);
M.Print(); //check
cout << M << endl; //check
Matrix M90(83,3);
cout << M90 << endl;
Matrix M2(5);
cout << M2 << endl;
M2 = M;
cout << M2 << endl; //check
Matrix M3(M);
cout << M3 << endl; //check
Matrix M4(5);
Matrix M6(4);
M4 = M*M6;
cout << M4 << endl; //check
Vector v(4,3);
Vector v2 = M*v;
cout << v2 << endl;
*/
//LES 4
int n=20; int m = 20;
Matrix mat1(n,m);
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
int ret = mat1.CG(res, vec1, eps, iter,0);

if (ret == 0) cout << "CG returned succesfully" << endl;

cout<< iter << " iterations used. " << endl;
cout << "Residual in CG = " << eps << endl;
cout << mat1*res<< endl;
}
