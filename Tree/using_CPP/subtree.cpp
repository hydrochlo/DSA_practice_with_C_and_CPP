#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
 
    Node(int val){
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(vector<int> &ar, int &idx){
    idx++;
    
    if(ar[idx] == -1){
        return NULL;
    }

    Node *root = new Node(ar[idx]);
    root->left = buildTree(ar, idx); //LEFT
    root->right = buildTree(ar, idx); // RIGHT

    return root;
}

bool isIdentical(Node *p, Node *q){
    if(p==NULL || q==NULL) return p==q;

    bool isLeftSame = isIdentical(p->left, q->left);
    bool isRightSame = isIdentical(p->right, q->right);

    return isLeftSame && isRightSame && p->data==q->data;
}

bool isSubTree(Node *root, Node *subroot){
    if(root==NULL || subroot==NULL) return root==subroot;
    if(root->data==subroot->data && isIdentical(root, subroot)){
        return true;
    }
    return isSubTree(root->left, subroot) || isSubTree(root->right, subroot);
}

int main(){
    vector<int> arr1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> arr2 = {3,4,-1,-1,6,-1,-1};

    int idx1 = -1;
    Node *root1 = buildTree(arr1, idx1);

    int idx2 = -1;
    Node *root2 = buildTree(arr2, idx2);

    cout << isSubTree(root1, root2) << endl;
    return 0;
}