#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

int maxSubArray_n2(int* array,int n){
    int best = 0;
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += array[b];
            best = fmax(best,sum);
        }
    }
    return best;
}

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

    srand(randomSeed);
    int* array = (int*) malloc(sizeof(int)*size);
    if(!array){
        perror("Malloc Failed");
        exit(1);
    }

    for(int i=0;i<size;i++){
        int x = rand() % 100;
        array[i] = 75 - x;
    }


    printf("N Result: %d\n",maxSubArray_n(array,size));
    printf("N^2 Result: %d\n",maxSubArray_n2(array,size));
    printf("N^3 Result: %d\n",maxSubArray_n3(array,size));


    return 0;
}