#include "Poisson.h"
int main(){
    int k[] ={1,10,2,3,3};
    double lambda []={2,2,2,3,100};
    for(int i=0;i<5;i++){
        printf("k= %d, lambda= %f, value= %Lf\n",k[i],lambda[i],poisson(k[i],lambda[i]));
    }
    return 0;
}