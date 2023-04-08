#pragma once //bescherming, gewoon zoda nie meerdere keren hetzelfde functietje er staat.
// Dit heeft te maken met de constructor

class Rational2{
public:
    //Rational2(int num, int den);
    //Rational2(int num);
    //Deze twee kunnen samengesteld worden door (kan met 3, maar dan moeten we 'num' specifieren voor 'den' vast te stellen.):
    Rational2(int num, int den=1);
    Rational2();
    int den()const;
    int num()const;

    //Destructeur (geheugen opruimen)
    ~Rational2();

    //Copy constructor
    Rational2(Rational2 const &);

    //We kunnen operator "=" veranderen (overloading of operator "=")
    Rational2& operator =(Rational2 const &);

    //We kunnen operator "-" overloaden op een unaire manier
    friend Rational2 operator -(Rational2 const &); // Dit maakt gebruik van iets wat ook buiten de classe gebruikt wordt
    //We kunnen operator "+" overloaden op een binaire manier
    friend Rational2 operator +(Rational2 const &,Rational2 const &); // Dit maakt gebruik van iets wat ook buiten de classe gebruikt wordt

private:
    int M_n;
    int M_d;
};
