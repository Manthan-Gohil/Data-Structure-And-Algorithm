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
// i is pass by reference means every recursive call shares the same i.
int solve(Node* root, int& i, int k){
    if(root == NULL){
        return -1;
    }
    // inorder traversal
    // Left
    int left = solve(root->left, i, k);
    if(left != -1){
        return left;
    }
    // Node
    i++;
    if(i==k){
        return root->data;
    }

    // Right
    return solve(root->right,i,k);

}

int kthSmallest(Node* root, int k){
    int i=0;
    int ans = solve(root,i,k);
    return ans;
}

int main(){
    Node* root = NULL;
    cout<<"Build BST : "<<endl;
    // 5,4,8,2,6,10,3,7
    take_input(root);

    cout<<"level order traversal : "<<endl;
    levelOrderTraversal(root);

    cout<<"Kth Smallest : "<<kthSmallest(root,3);

}