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

// method 1 recursive way
Node* LCA_BST(Node* root, Node* p, Node* q){
    if(root == NULL) return NULL;

    if(root->data < p->data && root->data < q->data){ // mtlab p and q right vale part me h
        return LCA_BST(root->right, p, q);
    }
    
    if(root->data > p->data && root->data > q->data){ // mtlab p and q left vale part me h
        return LCA_BST(root->left, p, q);
    }

    return root;

}

// method 2 iterative way
Node* LCA_BST2(Node* root, Node* p, Node* q){
    while(root != NULL){
        if(root->data < p->data && root->data < q->data){ 
        root = root->right;
    }
    
    else if(root->data > p->data && root->data > q->data){ 
        root = root->left;
    }
    else{
        return root;
    }
    }

}


int main(){
    Node* root = NULL;
    cout<<"Build BST : "<<endl;
    // 5,4,8,2,6,10,3,7
    take_input(root);

    cout<<"level order traversal : "<<endl;
    levelOrderTraversal(root);

}