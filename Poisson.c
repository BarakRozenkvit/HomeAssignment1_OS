#include <math.h>
#include <stdio.h>
#include <stdlib.h>
float factorial(int k){
    if(k==0)return 1;

    return factorial(k-1)*k;
}

long double poisson(int k,double lambda){
    return expf(-lambda)*((pow(lambda,k))/factorial(k));
}

int main(int argc,char *argv[]){
    if(argc!=3){
        printf("Error\n");
        exit(1);
    }
    double lambda=atof(argv[1]);
    int k=atoi(argv[2]);
    long double poi=poisson(k,lambda);
    printf("The poisson is: %Lf",poi);
    return 0;
}