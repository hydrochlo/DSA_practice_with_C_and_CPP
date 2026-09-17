#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int nodeid;
    struct Node *left;
    struct Node *right;
};

struct Node * createnode (int nid)
{
    struct Node *newnode;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    newnode->nodeid = nid;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void traversetree (struct Node * root)
{
    if (root == NULL) { return; }
    traversetree (root->left);
    traversetree (root->right);
    printf (" %d ", root->nodeid);
}


int main() {
    // Write C code here

    struct Node * n1, *n2, *n3, *n4, *n5, *n6;

    n1 = createnode (1);
    n2 = createnode (2);
    n3 = createnode (3);
    n4 = createnode (4);
    n5 = createnode (5);
    n6 = createnode (6);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n6;

    traversetree (n1);


    return 0;
}