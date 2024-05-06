#include <math.h>
#include "createArray.h"

int maxSubArray_n(int* array,int n){
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = fmax(array[k],sum+array[k]);
        best = fmax(best,sum);
    }
    return best;
}

int main(int argc,char* argv[]){
    if(argc != 3){
        perror("Expected 2 Arguments");
        return 1;
    }

    unsigned int randomSeed = atoi(argv[1]);
    int size = atoi(argv[2]);

    int* array = createArray(randomSeed,size);
    int result = maxSubArray_n(array,size);
    printf("Result for N: %d\n",result);


    return 0;
}