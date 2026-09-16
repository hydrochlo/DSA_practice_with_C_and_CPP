#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

void insert(int val){
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

void insertInSortedList(struct Node *p, int val){
    struct Node *q = NULL, *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    t->data = val;
    t->next = NULL;
    
    if(!first) first = t;
    else {
        while(p && p->data < val){
            q = p;
            p = p->next;
        }
        if(p==first){
            t->next = first;
            first = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
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
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    Display(first);

    insertInSortedList(first, 5);
    insertInSortedList(first, 55);
    Display(first);
    return 0;
}