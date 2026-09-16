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

int main(){

    int A[5] = {2,4,6,8,10};
    create(A, 5);
    printf("\nLength is : %d\n", Len(first));

    Display(first);
    return 0;
}