#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

int length(struct Node *p){
    int cnt = 0;
    while(p!=NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}

void create1(int A[], int n){
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

void create2(int A[], int n){
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

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
    printf("\n");
}


void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    } 
    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p) last->next = p;
    if(q) last->next = q;
}


int main(){
    int A[5] = {10, 20, 30, 40, 50};
    int B[7] = {5, 15, 25, 35, 45, 87, 97};

    create1(A, 5);
    create2(B, 7);

    Merge(first, second);
    Display(third);


    return 0;
}