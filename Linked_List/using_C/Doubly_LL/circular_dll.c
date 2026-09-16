#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n){
    
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
    
    Display(first);

    printf("\n");
    Reverse(first);
    Display(first);
    return 0;
}