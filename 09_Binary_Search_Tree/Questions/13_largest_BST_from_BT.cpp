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

    if(data == -1) return NULL;
    root = new Node(data);

    cout<<"Enter the left node data for "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right node data for "<<data<<endl;
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
        }else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
    cout<<endl;
}

class info {
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node* root, int &ans){
    // base case
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    // leaf nodes
    if(root->left == NULL && root->right == NULL){
        return {root->data, root->data, true, 1};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }else{
        currNode.isBST = false;
    }

    // answer update
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBST(Node* root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1, 10, 5, -1,-1,-1,39,-1,-1 = balanced
    // 1,10,5,-1,-1,-1,-1 = unbalanced
    levelOrderTraversal(root);


}