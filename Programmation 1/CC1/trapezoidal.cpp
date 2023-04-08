
typedef double (*pfn) (double);
double trapezoidal(double a, double b, pfn f, int n){

 double int_sum = 0;
 double delta_x = (b-a)/n;
 double start_point;
 double end_point;

 for (int ii=1; ii<=n; ++ii){
    start_point = a+(ii-1)*delta_x;
    end_point = start_point + delta_x;
    int_sum += (f(start_point)+f(end_point))*delta_x/2;
 }

 return int_sum;

}
