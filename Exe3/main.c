#include "Poisson.h"

int main(){
    printf("%.39Lf\n",calcPoisson(2,1));
    printf("%.39Lf\n",calcPoisson(2,10));
    printf("%.39Lf\n",calcPoisson(2,2));
    printf("%.39Lf\n",calcPoisson(3,3));
    printf("%.39Lf\n",calcPoisson(100,3));
    return 0;
}