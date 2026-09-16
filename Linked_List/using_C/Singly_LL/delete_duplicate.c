#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

int length(struct Node *p){
    int cnt = 0;
    while(p!=NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}


void inS(struct Node *p, int val){
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

void delDuplicate(struct Node *p){
    struct Node *q = p->next;
    while(q){
        if(p->data != q->data){
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

int main(){
    inS(first, 20);
    inS(first, 30);
    inS(first, 20);
    inS(first, 10);
    inS(first, 20);
    inS(first, 40);
    inS(first, 30);
    inS(first, 50);
    inS(first, 20);

    Display(first);
    delDuplicate(first);
    Display(first);

    return 0;
}