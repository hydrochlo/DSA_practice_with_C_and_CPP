#include <stdio.h>
#include "Queue.h"

struct Node *root=NULL;

void createTree(){
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q)){
        p = dequeue(&q);

        // For left child
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        // For right child
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preOrder(struct Node *p){
    if(p){
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void inOrder(struct Node *p){
    if(p){
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

void postOrder(struct Node *p){
    if(p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}

int height(struct Node *root){
    int x = 0, y = 0;
    if(root==0) return 0;

    x = height(root->lchild);
    y = height(root->rchild);

    if(x>y) return x+1;
    else y+1;
}

void levelOrder(struct Node *root){
    struct Queue q;
    create(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while(!isEmpty(q)){
        root = dequeue(&q);
        if(root->lchild){
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if(root->rchild){
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int main(){

    createTree();
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    return 0;
}