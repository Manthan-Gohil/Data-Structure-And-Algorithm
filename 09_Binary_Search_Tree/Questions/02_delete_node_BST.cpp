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

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* root, int value){
    if(root == NULL){
        return NULL;
    }

    if(root->data == value){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        
        // left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if(value < root->data){
        root->left = deleteNode(root->left, value);
        return root;
    }
    else{
        root->right = deleteNode(root->right, value);
        return root;
    }
}

int main(){
    Node* root = NULL;

    cout<<"BST : "<<endl;
    take_input(root);
// 10,8,21,7,27,5,4,3,-1
    cout<<"level order traversal : "<<endl;
    levelOrderTraversal(root);

    root = deleteNode(root, 21);

    cout<<"After deleted node : "<<endl;

    levelOrderTraversal(root);

}