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


void concat(struct Node *p, struct Node *q){
    third = p;
    while(p->next){
        p = p->next;
    }
    p->next = q;
}



int main(){
    int A[5] = {10, 20, 30, 40, 50};
    int B[5] = {5, 15, 25, 35, 45};

    create1(A, 5);
    create2(B, 5);

    Display(first);
    Display(second);

    // concat(first, second);
    concat(second, first);
    Display(third);

    return 0;
}