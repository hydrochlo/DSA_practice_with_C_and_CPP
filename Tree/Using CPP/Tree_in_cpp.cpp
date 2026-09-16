#include <iostream>
#include "QueueCPP.h"

using namespace std;

class Tree{
public:
    Node *root;
    Tree(){
        root = NULL;
    }
    void createTree();
    void preOrder(Node *p);
    void inOrder(Node *p);
    void postOrder(Node *p);
    void levelOrder(Node *p);
    int height(Node *p);
};

void Tree::createTree(){
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter root value: ";
    cin >> x;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty()){
        p = q.dequeue();

        // For left child
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        // For right child
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node *p){
    if(p){
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree::inOrder(Node *p){
    if(p){
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

void Tree::postOrder(struct Node *p){
    if(p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::levelOrder(Node *root){
    Queue q(100);
    cout << root->data << " ";
    q.enqueue(root);

    while(!q.isEmpty()){
        root = q.dequeue();
        if(root->lchild){
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }
        if(root->rchild){
            cout << root->rchild->data << " ";
            q.enqueue(root->rchild);
        }
    }
}

int Tree::height(Node *root){
    int x = 0, y = 0;
    if(root==0) return 0;

    x = height(root->lchild);
    y = height(root->rchild);

    if(x>y) return x+1;
    else return y+1;
}

int main(){

    Tree t;
    t.createTree();
    t.preOrder(t.root);

    return 0;
}