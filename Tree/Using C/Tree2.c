#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} Node;

Node *nodes[100];
int nodeCount = 0;

Node *getNode(int x){
    for(int i=0; i<nodeCount; i++){
        if(nodes[i]->data == x) return nodes[i];
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->lchild = newNode->rchild = NULL;
    nodes[nodeCount++] = newNode;
    return newNode;
}

void traverse(Node *root){
    if(root==NULL) return;
    printf("%d ", root->data);
    traverse(root->lchild);
    traverse(root->rchild);
}

int main(){
    int edges, u, v, dir;
    
    int edges;
    scanf("%d", &edges);
}