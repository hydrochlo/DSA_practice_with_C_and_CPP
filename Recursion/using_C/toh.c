#include <stdio.h>

int cnt;
void TOH(int n, int A, int B, int C){
    if(n>0){
        TOH(n-1, A, C, B);
        printf("(%d, %d)\n", A, C);
        cnt++;
        TOH(n-1, B, A, C);
    }
}

int main(){
    TOH(5, 1, 2, 3);
    printf("%d\n", cnt);
    return 0;
}