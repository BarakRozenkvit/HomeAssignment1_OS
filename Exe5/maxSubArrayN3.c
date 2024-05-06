#include <math.h>
#include "createArray.h"

int maxSubArray_n3(int* array,int n){
    int best = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int sum = 0;
            for (int k = a; k <= b; k++) {
                sum += array[k];
            }
            best = fmax(best,sum);
        }
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
    int result = maxSubArray_n3(array,size);
    printf("Result for N^3: %d\n",result);
    return 0;
}