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
    printf("\n");
}

int length(struct Node *p){
    int cnt = 0;
    while(p!=NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}

void Insert(struct Node *p, int index, int x){
    if(index<0 || index>length(p)){
        return;
    }
    struct Node *t;
    t = (struct Node *) malloc(sizeof(struct Node));
    t->data = x;
    if(index==0){
        t->next = first;
        first = t;
    } else {
        for(int i=0; i<index-1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main(){
    int A[3] = {3, 5, 7};
    create(A, 3);
    Display(first);

    // Insert(first, 0, 10);
    
    // Display(first);

    Insert(first, 3, 10);
    Display(first);

    return 0;
}