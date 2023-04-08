#pragma once
class ode{
private:

    double t_ini;
    double x_0;
    double t_end;
    double (*sfn) (double t, double x);

public:

    ode(double tini, double xini, double tend, double (*f)(double,double));
    double* euler(int n) const;

};
