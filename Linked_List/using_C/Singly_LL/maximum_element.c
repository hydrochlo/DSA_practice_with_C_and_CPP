#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int max_el(struct Node *p){
    int maxi = INT_MIN;
    while(p){
        if(p->data > maxi) maxi = p->data;
        p = p->next;
    }
    return maxi;
}

int Rmax_el(struct Node *p){
    int x = 0;
    if(!p){
        return INT_MIN;
    } else {
        x = Rmax_el(p->next);
        if(x > p->data) return x;
        else return p->data;
    }
}

int RRmax_el(struct Node *p){
    int x = 0;
    if(!p) return INT_MIN;
    x = RRmax_el(p->next);
    return (x > p->data ? x: p->data);
}

int main(){
    int A[5] = {2, 5, 9, 4, 8};
    create(A, 5);
    printf("%d ", max_el(first));
    printf("\n%d ", Rmax_el(first));
    printf("\n%d ", RRmax_el(first));
    return 0;
}