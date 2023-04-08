template<typename T> T lagrange(T* vx, T* vy, T x_in, const int n){
    T L = 1.;
    T result = 0.;
for (int index1 = 0; index1 < n; index1++){
    for (int index2 = 0; index2 < n; index2++){
            if (index1 != index2){
                L = L*(x_in-vx[index2])/(vx[index1]-vx[index2]);
            }
    }
    result = result + vy[index1]*L;
    L = 1.;
}
return result;
};

