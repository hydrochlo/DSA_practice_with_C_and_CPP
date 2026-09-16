#include <stdio.h>

int fun(int n){
    if(n>100){
        return n-10;
    } 
    else {
        return fun(fun(n+11));
    }
}

int main(){
    int a = 95, r;
    r = fun(a);
    printf("%d\n", r);
    return 0;
}