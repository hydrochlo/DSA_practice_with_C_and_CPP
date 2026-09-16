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

int Search(struct Node *p, int key){
    while(p){
        if(key == p->data){
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int RSearch(struct Node *p, int key){
    if(!p) return 0;
    if(key == p->data) return 1;
    return Search(p->next, key);
}

int main(){
    int A[5] = {2, 5, 9, 4, 8};
    create(A, 5);
    printf("%s", (RSearch(first, 10) ? "FOUND": "NOT FOUND"));
    return 0;
}