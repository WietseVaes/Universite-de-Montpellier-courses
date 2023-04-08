typedef double (*pfn) (double);
double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int n_max);

