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

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Del(struct Node *p, int index){
    struct Node *q = NULL;
    int x = -1;
    if(index<1 || index>length(p)) return -1;
    if(index==1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    } else {
        for(int i=0; i<index-1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;

    }
}

int main(){
    insert(10);
    insert(5);
    insert(15);
    insert(13);
    insert(20);
    Display(first);
    Del(first, 2);
    Display(first);
    return 0;
}