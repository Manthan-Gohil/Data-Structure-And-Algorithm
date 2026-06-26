// height = longest path between root node and leaf node
// TC O(N) SC O(N)
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

int heightOfTree(Node* root){
    if(root == NULL) return 0;

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

int main(){
    Node* root = NULL;
    // 1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, 9, 8, -1, -1, -1, -1
    root = buildTree(root);
    levelOrderTraversal(root);
    cout<<"Height of tree : "<<heightOfTree(root)<<endl;
}