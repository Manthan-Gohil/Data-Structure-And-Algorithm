#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout<<"Enter data : "<<endl;
    cin>>data;

    root = new Node(data);

    if(data == -1) return NULL;

    cout<<"Enter the left node data for "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right node data for "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void preOrder(Node* root, int &cnt){
    
    if(root == NULL) return;
    
    if(root->left == NULL && root->right == NULL){
        cnt++;
    }
    preOrder(root->left, cnt);
    preOrder(root->right, cnt);
}

int countLeafNodes(Node* root){
    int cnt = 0;
    preOrder(root, cnt);
    return cnt;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout<<"Count the leaf nodes "<<countLeafNodes(root);

}