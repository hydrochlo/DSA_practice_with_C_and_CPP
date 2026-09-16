#include <stdio.h>
#include <stdlib.h>

// typedef something otherthing
struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *nodes[100], *root;
int nodeCount = 0;

struct Node *getNode(int x){
    for(int i=0; i<nodeCount; i++){
        if(nodes[i]->data == x) return nodes[i];
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->lchild = newNode->rchild = NULL;

    if(nodeCount==0) root = newNode;

    nodes[nodeCount] = newNode;
    nodeCount++;
    return newNode;
}

void traverse(struct Node *root){
    if(root==NULL) return;
    printf("%d ", root->data);
    traverse(root->lchild);
    traverse(root->rchild);
}

int height(struct Node *root){
    int x = 0, y = 0;
    if(root==0) return 0;

    x = height(root->lchild);
    y = height(root->rchild);

    if(x>y) return x+1;
    else y+1;
}

int main(){
    int edges, u, v, dir;
    scanf("%d", &edges);

    for(int i=0; i<edges; i++){
        scanf("%d%d%d", &u, &v, &dir);

        struct Node *parent = getNode(u);
        struct Node *child = getNode(v);

        if(dir==-1) parent->lchild = child;
        else if(dir==1) parent->rchild = child;
    }

    traverse(root);
    printf("Height = %d", height(root));
    return 0;
}