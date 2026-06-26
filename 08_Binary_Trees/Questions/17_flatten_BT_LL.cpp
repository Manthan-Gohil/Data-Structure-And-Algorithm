// flatten binary tree to linked list
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

    root = new Node(data);

    if(data == -1) return NULL;

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

Node* nextRight = NULL;
void flatten(Node* root){
    if(root == NULL) return;

    // move in reverse preorder
    flatten(root->right);
    flatten(root->left);
    
    root->left = NULL;
    root->right = nextRight;
    nextRight = root;
}


// verifying (does not need this function in leetcode)
void printFlattened(Node* root){
    Node* curr = root;

    while(curr){
        cout << curr->data << " ";

        if(curr->left != NULL){
            cout << "\nError: left child exists!" << endl;
            return;
        }

        curr = curr->right;
    }
    cout << endl;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1,2,3,-1,-1,4,-1,-1,5,-1,6,-1,-1
    cout<<"level order traversal : "<<endl;
    levelOrderTraversal(root);

    flatten(root);
    cout<<"After Flattened : "<<endl;
    printFlattened(root);

}