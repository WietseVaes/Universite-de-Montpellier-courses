#pragma once //bescherming, gewoon zoda nie meerdere keren hetzelfde functietje er staat.

class Rational{
public:
    void set(int num,int den);
    int den()const;
    int num()const;

private:
    int M_n;
    int M_d;
};
