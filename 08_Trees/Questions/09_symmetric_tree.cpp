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

bool isMirror(Node* left, Node* right){
    if(left == NULL && right == NULL) return true;

    if(left == NULL || right == NULL) return false;

    if(left->data != right->data) return false;

    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}
// symmetric tree
bool isSymmetric(Node* root){
    if(root == NULL){
        return true;
    }

    return isMirror(root->left, root->right);
}

int main(){
    Node* root = NULL;
    // 1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3,-1,-1
    root = buildTree(root);

    cout<<"is symmetric : "<<isSymmetric(root);

}