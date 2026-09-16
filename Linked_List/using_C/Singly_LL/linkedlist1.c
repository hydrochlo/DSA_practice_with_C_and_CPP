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

void recDisplay(struct Node *p){
    if(p!=NULL){
        // printf("%d ", p->data);
        recDisplay(p->next);
        printf("%d ", p->data);
    }
}

int main(){
    int A[5] = {2, 5, 9, 4, 8};
    create(A, 5);
    Display(first);
    printf("\n");
    recDisplay(first);
    return 0;
}