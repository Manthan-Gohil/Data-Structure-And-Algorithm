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

Node* helper(vector<int> &inOrder, vector<int> &postOrder, int &postIdx, int left, int right){
    if(left > right) return NULL;

    Node* root = new Node(postOrder[postIdx]);

    int inIdx = search(inOrder,left,right,postOrder[postIdx]);
    // change move in reverse because of postorder LRN
    postIdx--;
    // change in recursion calling
    root->right = helper(inOrder, postOrder, postIdx, inIdx+1, right);
    root->left = helper(inOrder, postOrder, postIdx, left, inIdx-1);

    return root;
}

Node* buildTree(vector<int> &inOrder, vector<int> &postOrder){
    // take root from last postorder LRN
    int postIdx = postOrder.size()-1;

    return helper(inOrder, postOrder, postIdx, 0, inOrder.size()-1);
}

int main(){
    vector<int> inOrder = {9,3,15,20,7};
    vector<int> postOrder = {9,15,7,20,3};

    Node* root = buildTree(inOrder, postOrder);
    cout<<root->data;
}