#include "poisson.h"

void poisson(float lambda, int k){
    long factorial = 1;
    for(int i = 1; i <= k; i++){
        factorial *= i;
    }
    if(k == 0){
        factorial = 1;
    }
    long double ans = (long double)pow(lambda, k) * expf(-lambda) / (long double)factorial;
    printf("%Lf\n", ans);

}