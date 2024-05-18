#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Error\n");
        return 1;
    }
    float lambda = atof(argv[1]);
    int k = atoi(argv[2]);
    long factorial = 1;
    for(int i = 1; i <= k; i++){
        factorial *= i;
    }
    if(k == 0){
        factorial = 1;
    }
    long double ans = (long double)pow(lambda, k) * expf(-lambda) / (long double)factorial;
    printf("%Lf\n", ans);

    return 0;
}
