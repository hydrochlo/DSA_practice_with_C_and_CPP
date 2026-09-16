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

int isLoop(struct Node *f){
    struct Node *p, *q;
    p = q = f;
    
    do{
        p = p->next;
        q = q->next ? q->next->next: q->next;
        // q = q->next;
        q = (q ? q->next: q);
    } while(p && q && p!=q);
    if(p==q) return 1;
    return 0;
}

int main(){
    struct Node *t1, *t2;

    int A[6] = {10, 20, 30, 40, 50, 60};
    create(A, 6);

    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;

    printf("%d\n", isLoop(first));
    return 0;
}