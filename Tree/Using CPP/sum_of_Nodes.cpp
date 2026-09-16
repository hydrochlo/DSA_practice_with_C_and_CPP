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

int sumOfNodes(Node *r){
    if(r==NULL) return 0;
    
    int leftN = sumOfNodes(r->left);
    int rightN = sumOfNodes(r->right);

    return (leftN + rightN) + r->data;
}

int main(){
    vector<int> arr = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node *root = buildTree(arr);
    
    cout << "Sum of Nodes: " << sumOfNodes(root) << endl;
    return 0;
}