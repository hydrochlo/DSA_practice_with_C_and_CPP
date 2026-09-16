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

void MakeFirst(struct Node *p, int key){
    struct Node *q = NULL;

    while(p){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
        }
        q = p;
        p = p->next;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(){
    int A[5] = {2, 5, 9, 4, 8};
    create(A, 5);
    MakeFirst(first, 9);
    Display(first);
    return 0;
}