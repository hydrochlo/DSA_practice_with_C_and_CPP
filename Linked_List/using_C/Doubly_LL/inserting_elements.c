#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    int i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for(i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }

}

void Display(struct Node *p){
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}

int Len(struct Node *p){
    int l=0;
    while(p){
        l++;
        p = p->next;
    }
    return l;
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if(index<0 || index>Len(first)) return;
    if(index==0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    } else {
        for(i=0; i<index-1; i++) p = p->next;
        // q = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next) p->next->prev = t;
        p->next = t;
    }
}


int main(){

    int A[5] = {2,4,6,8,10};
    create(A, 5);
    
    Display(first);

    Insert(first, 5, 50);

    Display(first);
    return 0;
}