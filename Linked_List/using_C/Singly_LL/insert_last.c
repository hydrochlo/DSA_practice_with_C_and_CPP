#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

void InsertLast(int val){
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;
    if(!first){
        first = last = t;
    } else {
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

int main(){
    InsertLast(10);
    Display(first);
    InsertLast(20);
    Display(first);
    InsertLast(30);
    Display(first);
    return 0;
}