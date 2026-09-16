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

// Pre-Order Traversal : Root -> left -> Right
void preOrder(Node *r){
    if(r==NULL) return;
    
    cout << r->data << "\n";
    preOrder(r->left);
    preOrder(r->right);
}

// In-Order Traversal : Left -> Root -> Right
void inOrder(Node *r){
    if(r==NULL) return;
    
    inOrder(r->left);
    cout << r->data << "\n";
    inOrder(r->right);
}

// Post-Order Traversal : Left -> Root -> Right
void postOrder(Node *r){
    if(r==NULL) return;
    
    postOrder(r->left);
    postOrder(r->right);
    cout << r->data << "\n";
}

// Level-Order
// void levelOrder(Node *r){
//     queue<Node *> q;
//     q.push(r);

//     while(q.size()>0){
//         Node *curr = q.front();
//         q.pop();

//         cout << curr->data << " ";

//         if(curr->left!=NULL) q.push(curr->left);
//         if(curr->right!=NULL) q.push(curr->right);
//     }
//     cout << endl;
// }

void levelOrder(Node *r){
    queue<Node *> q;
    q.push(r);
    q.push(NULL);

    while(q.size()>0){
        Node *curr = q.front();
        q.pop();

        if(curr==NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            } else break;    
        }
        cout << curr->data << " ";

        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
    cout << endl;
}


int main(){
    vector<int> arr = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node *root = buildTree(arr);

    cout << root->data << endl;

    // cout << root->left->data << endl;
    // cout << root->right->data << endl;
    // cout << root->right->left->data << endl;
    // cout << root->right->right->data << endl;

    // preOrder(root);
    // inOrder(root);

    levelOrder(root);
    return 0;
}