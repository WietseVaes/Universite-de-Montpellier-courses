template<typename T> double sum(T MM){
    double res;
    int n = MM.dimn;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            res += MM(i,j);
        }
    }
    return res;
}
