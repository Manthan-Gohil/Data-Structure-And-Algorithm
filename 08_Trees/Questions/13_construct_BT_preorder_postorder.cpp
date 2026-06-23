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

Node* helper(vector<int> &preOrder, vector<int> &postOrder, int preStart, int preEnd, int postStart, int postEnd){
    if(preStart > preEnd){
        return NULL;
    }

    Node* root = new Node(preOrder[preStart]);

    // leaf node
    if(preStart == preEnd){
        return root;
    }

    // root of left subtree
    int leftRoot = preOrder[preStart+1];

    // find leftSubtree in postorder
    int idx = postStart;
    while(postOrder[postStart] != leftRoot){
        idx++;
    }

    // number of nodes in leftsubtree
    int leftSize = idx - postStart + 1;

    root->left = helper(preOrder, postOrder, preStart+1, preStart + leftSize, postStart, idx);
    root->right = helper(preOrder, postOrder, preStart+leftSize+1, preEnd, idx+1, postEnd-1);

    return root;
}

Node* buildTree(vector<int> &preOrder, vector<int> &postOrder){
    int n = preOrder.size();

    return helper(preOrder, postOrder, 0, n-1, 0, n-1);
}

int main(){

    vector<int> preOrder = {1,2,4,5,3,6,7};
    vector<int> postOrder = {4,5,2,6,7,3,1};

    Node* root = buildTree(preOrder, postOrder);
}