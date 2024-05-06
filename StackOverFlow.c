#include <stdio.h>
void infiniteRecurstion(){
    infiniteRecurstion();
}
int main(){
    infiniteRecurstion();
    return 0;
}