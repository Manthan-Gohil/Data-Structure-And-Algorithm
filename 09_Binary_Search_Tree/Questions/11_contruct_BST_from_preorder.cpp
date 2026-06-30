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

Node* insertToBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data < root->data){
        root->left = insertToBST(root->left,data);
    }
    else{
        root->right = insertToBST(root->right,data);
    }
    return root;    
}

void take_input(Node* root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertToBST(root,data);
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

Node* solve(vector<int> &preOrder, int mini, int maxi, int &i){
    if(i >= preOrder.size()) return NULL;

    if(preOrder[i] < mini || preOrder[i] > maxi){
        return NULL;
    }

    Node* root = new Node(preOrder[i++]);
    root->left = solve(preOrder, mini,root->data,i);
    root->right = solve(preOrder, root->data, maxi, i);
    return root;
}

Node* preorderToBST(vector<int> preOrder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preOrder, mini, maxi, i);
}

int main(){

}