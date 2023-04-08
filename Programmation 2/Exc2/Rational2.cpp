#include "Rational2.hpp"

 Rational2::Rational2(int num,int den):M_d(den), M_n(num)
    {
        //Hier kunnen we functies insteken (die gezet zijn in Rational2.hpp (vaak private))
    }
    /*
 Rational2::Rational2(int num)
    {
     M_d = 1;
     M_n = num;
    }
    */
    // Aanstellen van een constructie kan op twee manieren de vorige en de volgende.
  Rational2::Rational2()
    {
     M_d = 1;
     M_n = 0;
    }

    //Desrtuctor
    Rational2::~Rational2()
    {
    }

    //copy constructor
    Rational2::Rational2(Rational2 const& p){
    M_n = p.M_n;
    M_d = p.M_d;
    }

    //Overloading "="
    Rational2& Rational2::operator=(Rational2 const & p)
    {
        M_n = p.M_n;
        M_d = p.M_d;

        return *this; //this is een pointer
    }

    //unairy "="
    Rational2 operator-(Rational2 const & p)
    {
        Rational2 t;
        t.M_n = -p.M_n;
        t.M_d = p.M_d;

        return t; //this is een pointer
    }

        Rational2 operator+(Rational2 const & p,Rational2 const & q)
    {
        Rational2 t;
    //zelf functie maken
    if(p.M_d==q.M_d)
    {

    }
    else
    {

    }

    }

 int Rational2::den()const {return M_d;}
 int Rational2::num()const {return M_n;}

