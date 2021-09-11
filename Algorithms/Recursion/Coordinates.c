#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int add(int x, int y){
    return x+y;
}

int main(){
    int a = add(2,3) * add(2,3);
    printf("%d", a);    
}