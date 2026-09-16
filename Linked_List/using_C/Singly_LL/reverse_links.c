// Reversing the links of a linkedlist
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

void reverse_links(struct Node *p){
    struct Node *q = NULL, *r = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main(){
    inS(first, 2);
    inS(first, 4);
    inS(first, 6);
    inS(first, 8);
    inS(first, 10);

    Display(first);
    reverse_links(first);

    Display(first);
    return 0;
}