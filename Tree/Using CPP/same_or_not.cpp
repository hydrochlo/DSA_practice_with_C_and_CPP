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

bool isSameTree(Node *p, Node *q){
    if(p==NULL || q==NULL) return p==q;

    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);

    return isLeftSame && isRightSame && p->data==q->data;
}

int main(){
    vector<int> arr1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> arr2 = {1,2,-1,-1,4,4,-1,-1,5,-1,-1};

    int idx1 = -1;
    Node *root1 = buildTree(arr1, idx1);

    int idx2 = -1;
    Node *root2 = buildTree(arr2, idx2);
    
    if(isSameTree(root1, root2)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}