#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(TreeNode* root, vector<int> &in){
    if(root == NULL) return;

    // LNR
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void preorder(TreeNode* root, vector<int> &in, int index){
    if(root == NULL) return;

    // NLR
    root->data = in[index++];

    preorder(root->left, in, index);
    preorder(root->right, in, index);
}


void convert_BST_To_MinHeap(TreeNode* root){
    if(root == NULL) return;
    vector<int> inorderVal;
    
    inorder(root, inorderVal);
    
    // now preorder to insert values
    int index = 0;
    preorder(root, inorderVal, index);
}
void preorderPrint(TreeNode* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}


int main(){
    // Constructing the Binary Search Tree (BST)
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    convert_BST_To_MinHeap(root);
    preorderPrint(root);

}