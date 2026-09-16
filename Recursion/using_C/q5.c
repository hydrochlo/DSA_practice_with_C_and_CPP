#include <stdio.h>

void cnt(int n){
    static int d = 1;
    printf("%d", n);
    printf("%d", d);
    d++;
    if(n>1) cnt(n-1);
    printf("%d", d);
}

int main(){
    
}