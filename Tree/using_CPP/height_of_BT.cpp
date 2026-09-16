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


Node *buildTree(vector<int> ar){
    static int idx = -1;
    idx++;
    
    if(ar[idx] == -1){
        return NULL;
    }

    Node *root = new Node(ar[idx]);
    root->left = buildTree(ar); //LEFT
    root->right = buildTree(ar); // RIGHT

    return root;
}

int height(Node *r){
    if(r==NULL) return 0;
    
    int leftHt = height(r->left);
    int rightHt = height(r->right);

    return max(leftHt, rightHt) + 1;
}

int main(){
    vector<int> arr = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node *root = buildTree(arr);
    
    cout << height(root) << endl;
    return 0;
}