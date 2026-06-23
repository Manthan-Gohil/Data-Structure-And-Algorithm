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

int search(vector<int> &inOrder, int left, int right, int val){
    for(int i=left;i<=right;i++){
        if(inOrder[i] == val){
            return i;
        }
    }
    return -1;
}

Node* helper(vector<int> &preOrder, vector<int> &inOrder, int &preIdx, int left, int right){
    if(left > right){
        return NULL;
    }

    Node* root = new Node(preOrder[preIdx]);
    
    int inIdx = search(inOrder, left, right, preOrder[preIdx]);
    preIdx++;

    root->left = helper(preOrder, inOrder, preIdx, left, inIdx-1);
    root->right = helper(preOrder, inOrder, preIdx, inIdx+1, right);

    return root;
}

Node* buildTree(vector<int> preOrder, vector<int> inOrder){
    int preIdx = 0;
    return helper(preOrder, inOrder, preIdx, 0, inOrder.size()-1);
}

int main(){
    vector<int> preOrder = {3,9,20,15,7};
    vector<int> inOrder = {9,3,15,20,7};
    Node* root = buildTree(preOrder,inOrder);

    cout<<root->data<<" ";
}