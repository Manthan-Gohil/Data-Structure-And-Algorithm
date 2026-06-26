// summ tree ->
// given a binary tree return true if for every node X in the tree other than the leaves, its value is equal to its left subtree value and its right subtree value. else return false
// The value of a node must be exactly equal to the total sum of all the nodes in its left subtree plus all the nodes in its right subtree.
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
    cout<<"Enter data : "<<ends;
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
// TC O(N) SC O(height)
// first store is sum from left subtree and right subtree is equal and in second store the sum
pair<bool,int> isSumTreeFast(Node* root){
    if(root == NULL){
        pair<bool,int> p = {true,0};
        return p;
    }
    // ignoring the leaf nodes
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = {true, root->data};
        return p;
    } 

    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool cond = root->data == leftSum + rightSum;

    pair<bool,int> ans;
    if(isLeftSumTree && isRightSumTree && cond){
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    }else{
        ans.first = false;
    }
    return ans;
}

bool isSumTree(Node* root){
    return isSumTreeFast(root).first;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 3,1,-1,-1,2,-1,-1
    levelOrderTraversal(root);

    cout<<"is sum tree : "<<isSumTree(root);
}