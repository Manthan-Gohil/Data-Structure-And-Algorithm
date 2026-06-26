// Given a Binary Tree, find its Boundary Traversal. The traversal
// should be in the following order:
//
// 1. Left boundary nodes: defined as the path from the root to the
// left-most node ie- the leaf node you could reach when you
// always travel preferring the left subtree over the right
// subtree.
// 2. Leaf nodes: All the leaf nodes except for the ones that are
// part of left or right boundary.
// 3. Reverse right boundary nodes: defined as the path from the
// right-most node to the root. The right-most node is the leaf
// node you could reach when you always travel preferring the
// right subtree over the left subtree. Exclude the root from this
// as it was already included in the traversal of left boundary
// nodes.
//
// Note: If the root doesn't have a left subtree or right subtree,
// then the root itself is the left or right boundary.

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
    cout<<"Enter the data"<<endl;
    cin>>data;
    if(data == -1) return NULL;
    root = new Node(data);

    cout<<"Enter the left node data for : "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right node data for : "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}


void levelOrderTraversal(Node* root){
    queue<Node*> q;

    if(root == NULL) return;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

// approach ->
// 1. move to left node except leaf node
// 2. then print all the leaf nodes
// 3. then move in reverse order to print the right side nodes

// print left side node
void traverseLeft(Node* root, vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left != NULL){
        traverseLeft(root->left, ans);
    }else{
        traverseLeft(root->right, ans);
    }
}

// print leaf nodes (inorder traversal method)
void traverseLeaf(Node* root, vector<int> &ans){
    // base case
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

// right node traverse
void traverseRight(Node* root, vector<int> &ans){
    // base case
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->right != NULL){
        traverseRight(root->right, ans);
    }else{
        traverseRight(root->left, ans);
    }

    // wapas aagye
    ans.push_back(root->data);
}

vector<int> boundry(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    ans.push_back(root->data);
    // left part print/store
    traverseLeft(root->left, ans);

    // traverse leaf node

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);
    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    vector<int> ans = boundry(root);

    for(auto num : ans){
        cout<<num<<" ";
    }

}