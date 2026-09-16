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

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

int length(struct Node *p){
    int cnt = 0;
    while(p!=NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}

int Rlength(struct Node *p){
    if(!p) return 0;
    return 1+Rlength(p->next);
}

int main(){
    int A[5] = {2, 5, 9, 4, 8};
    create(A, 5);
    Display(first);
    printf("\nlength of the linkedlist is = %d", length(first));
    printf("\nlength of the linkedlist is = %d", Rlength(first));
    return 0;
}