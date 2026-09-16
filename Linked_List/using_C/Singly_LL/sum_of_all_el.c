#include <stdio.h>
#include <stdlib.h>

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

int Add(struct Node *p){
    int sum = 0;
    while(p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int recAdd(struct Node *p){
    if(!p) return 0;
    return p->data + recAdd(p->next);
}

int main(){
    int A[5] = {2, 5, 9, 4, 8};
    create(A, 5);
    // Display(first);
    printf("Sum of all the elements of ll is = %d", Add(first));
    printf("\nSum of all the elements of ll(rec) is = %d", recAdd(first));
    return 0;
}