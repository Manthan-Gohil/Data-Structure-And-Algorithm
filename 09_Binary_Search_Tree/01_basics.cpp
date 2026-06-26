// binary search tree ->
// left sub tree node values are less than root node value
// right sub tree node values are greater than root node value

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertToTree(Node* root, int d){
    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d < root->data){
        // left part me insert krna h
        root->left = insertToTree(root->left,d);
    }
    else{
        // right part me insert krna hai
        root->right = insertToTree(root->right,d);
    }
    return root;
}

void take_input(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertToTree(root, data);
        cin>>data;
    }
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
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    take_input(root);
    // 10,8,21,7,27,5,4,3,-1

    cout<<"Printing the BST : "<<endl;
    levelOrderTraversal(root);

    return 0;
}