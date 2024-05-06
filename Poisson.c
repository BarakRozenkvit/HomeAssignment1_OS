#include "Poisson.h"
float factorial(int k){
    if(k==0)return 1;

    return factorial(k-1)*k;
}

long double poisson(int k,double lambda){
    return expf(-lambda)*((pow(lambda,k))/factorial(k));
}
