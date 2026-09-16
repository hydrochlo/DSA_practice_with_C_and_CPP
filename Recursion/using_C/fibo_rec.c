#include <stdio.h>

int F[10];
int rec_fib(int n){
    if(n <= 1) return n;
    return rec_fib(n-2) + rec_fib(n-1);
}

int m_fib(int n){
    if(n<=1){
        F[n] = n;
        return n;
    } else {
        if(F[n-2]==-1){
            F[n-2] = m_fib(n-2);
        }
        if(F[n-1]==-1){
            F[n-1] = m_fib(n-1);
        }
        return F[n-2] + F[n-1];
    }
}

int main(){
    int i;
    for(i=0; i<10; i++) F[i] = -1;
    printf("%d \n", rec_fib(10));
    printf("%d \n", m_fib(10));
}
