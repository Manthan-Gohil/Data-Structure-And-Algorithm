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

// TC O(N) SC O(height of tree)
bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL && root2 != NULL){
        return false;
    }
    if(root1 != NULL && root2 == NULL){
        return false;
    }

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if(left && right && value){
        return true;
    }else{
        return false;
    }
}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;
    root1 = buildTree(root1);
    levelOrderTraversal(root1);

    root2 = buildTree(root2);
    levelOrderTraversal(root2);


}