#include "createArray.h"

int* createArray(int randomSeed,int size){
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
    return array;
}