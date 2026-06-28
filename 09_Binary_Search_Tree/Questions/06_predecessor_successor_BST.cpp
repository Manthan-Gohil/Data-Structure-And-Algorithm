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

// TC O(N) SC O(1)
pair<int,int> pre_succ_BST(Node* root, int key){
    Node* temp = root;
    int pre = -1;
    int succ = -1;

    // found key 
    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }

        if(temp->data < key){
            pre = temp->data;
            temp = temp->right;
        }
    }

    // pred succ

    // pred
    Node* leftTree = temp->left;
    while(leftTree != NULL){
        pre = leftTree->data;
        leftTree = leftTree->right;
    }
    // succ
    Node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pre,succ};
}

int main(){
    Node* root = NULL;
    cout<<"Build BST : "<<endl;
    // 5,4,8,2,6,10,3,7
    take_input(root);

    cout<<"level order traversal : "<<endl;
    levelOrderTraversal(root);

    cout<<"Pred : "<<pre_succ_BST(root,4).first<<" ";
    cout<<"Succ : "<<pre_succ_BST(root,4).second;  

}