#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if(t==NULL) {
        printf("Queue is full.");
        return;
    }

    if(front==NULL){
        t->data = x;
        front = rear = t;
        t->next = NULL;
    } else {
        t->data = x;
        t->next = NULL;
        rear->next = t;
        rear = t;
    }
}

int dequeue(){
    int x = -1;
    if(front==NULL) printf("Queue is empty.");
    else {
        x = front->data;
        front = front->next;
    }
    return x;
}

void Display(){
    struct Node *t = front;
    if(t==NULL) printf("Queue is empty");
    else {
        while(t!=NULL){
            printf("%d ", t->data);
            t = t->next;
        }
    }   
}

int main(){
    struct Node q;
    enqueue(5);
    enqueue(10);
    enqueue(15);

    // printf("%d ", dequeue());
    // printf("%d ", dequeue());
    // printf("%d ", dequeue());

    Display();
    return 0;
}