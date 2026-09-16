#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} Node;

Node *nodes[100], *root;
int nodeCount = 0;

Node *getNode(int x){

    for(int i=0; i<nodeCount; i++){
        if(nodes[i]->data == x) return nodes[i];
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->lchild = newNode->rchild = NULL;

    if(nodeCount==0) root = newNode;

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
    scanf("%d", &edges);

    for(int i=0; i<edges; i++){
        scanf("%d%d%d", &u, &v, &dir);

        Node *parent = getNode(u);
        Node *child = getNode(v);

        if(dir==-1) parent->lchild = child;
        else if(dir==1) parent->rchild = child;
    }

    traverse(root);
    return 0;
}