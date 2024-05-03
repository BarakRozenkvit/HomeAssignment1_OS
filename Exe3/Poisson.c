#include "Poisson.h"

long double calcPoisson(int lambda,int k){
    long double lambda_pow_k = powl(lambda,k);
    long double k_fact = factorial(k);
    long double e_in_minus_lambda = (long double)expf(-lambda);
    return (lambda_pow_k/k_fact)*e_in_minus_lambda;
}

int factorial(int k){
    int result = 1;
    for(int i=1;i<=k;i++){
        result *= i;
    }
    return result;
}

int main(int argc,char** argv){
    if(argc == 3){
        int lambda = atoi(argv[1]);
        int k = atoi(argv[2]);
        printf("%.39Lf",calcPoisson(lambda,k));
        return 0;
    }
    printf("Error\n");
    return 1;
    }


