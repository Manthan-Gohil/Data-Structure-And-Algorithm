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
    cout<<"Enter data"<<endl;
    cin>>data;
    
    if(data == -1) return NULL;
    root = new Node(data);

    cout<<"Enter the left node for data : "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right node for data : "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subTree){
    if(root == NULL) return false;

    if(isIdentical(root,subTree)){
        return true;
    }

    return isSubtree(root->left, subTree) || isSubtree(root->right, subTree);
}

int main(){
    Node* root = NULL;
    // 3,4,1,-1,-1,2,-1,-1,5,-1,-1
    Node* subTree = NULL;
    // 4,1,-1,-1,2,-1,-1
    root = buildTree(root);
    subTree = buildTree(subTree);
    cout<<"is subtree : "<<isSubtree(root, subTree);
}