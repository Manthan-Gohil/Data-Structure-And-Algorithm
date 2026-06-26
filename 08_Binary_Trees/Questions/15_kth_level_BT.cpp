// print kth level nodes of BT
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

void kth_level(Node* root, int k){
    if(root == NULL) return;

    if(k == 1){
        cout<<root->data<<" ";
        return;
    }

    kth_level(root->left, k-1);
    kth_level(root->right, k-1);
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1
    cout<<"Level order traversal"<<endl;
    levelOrderTraversal(root);
    cout<<"kth nodes : "<<endl;
    kth_level(root,3);
}