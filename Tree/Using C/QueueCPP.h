#ifndef QueueCPP_h
#define QueueCPP_h

#include <iostream>
using namespace std;

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
};



class Queue{
    private:
        int front;
        int rear;
        int size;
        Node **Q;
    public:
        Queue(){
            front = rear = -1;
            size = 10;
            Q = new Node *[size];
        }
        Queue(int sz){
            front = rear = -1;
            this->size = sz;
            Q = new Node *[this->size];
        }
    void enqueue(Node *x);
    Node *dequeue();
    bool isEmpty(){
        return front==rear;
    }
    void Display();
};

void Queue::enqueue(Node *x){
    if(rear==size-1){
        printf("Queue is full.\n");
    }
    else {
        Q[++rear] = x;
    }
}

void Queue::Display(){
    for(int i=front+1; i<=rear; i++) printf("%d ", Q[i]);
    printf("\n");
}

Node *Queue::dequeue(){
    Node *x = NULL;
    if(front==rear) printf("Queue is empty.\n");
    else x = Q[++front];
    return x;
}

#endif