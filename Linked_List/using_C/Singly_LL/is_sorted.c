#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isSorted(struct Node *p){
    int x = INT_MIN;
    while(p){
        if(p->data < x) return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

int main(){
    
    insert(5);
    insert(10);
    insert(13);
    insert(15);
    insert(20);
    Display(first);
    if(isSorted(first)) printf("YES\n");
    else printf("NO\n");
    return 0;
}