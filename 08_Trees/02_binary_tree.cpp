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

// preorder build tree: TC O(n)
// static int idx = -1;
// Node* buildTree(vector<int> &preorder){
//     idx++;
//     if(preorder[idx] == -1) return NULL;

//     Node* root = new Node(preorder[idx]);
//     root->left = buildTree(preorder);
//     root->right = buildTree(preorder);
    
//     return root;
// }

Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    root = new Node(data);

    if(data == -1) return NULL;

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// preorder traversal TC(O(N))
void preOrder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// inorder traversal TC(O(N))
void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// postorder traversal TC(O(N))
void postOrder(Node* root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// level order traversal (iterative way) using queue
void levelOrder(Node* root){
    queue<Node*> q;
    if(root == NULL) return;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
    cout<<endl;
}

// level order traversal (with each level have new line)
void levelOrder2(Node* root){
    queue<Node*> q;
    if(root == NULL) return;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){ // purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){
                // queue still has some child nodes
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
    cout<<endl;
}

int main(){
    // vector<int> preorder = {1,3,7,-1,-1,11,-1,-1,5,17,-1,-1,-1};
    // Node* root = buildTree(preorder);
    Node* root = NULL;
    root = buildTree(root);
    
    // cout<<"preorder traversal : ";
    // preOrder(root);
    // cout<<endl;
    // cout<<"inorder traversal : ";
    // inOrder(root);
    // cout<<endl;
    // cout<<"postorder traversal : ";
    // postOrder(root);
    // cout<<endl;
    // cout<<"levelorder traversal : ";
    // levelOrder(root);
    cout<<"levelorder traversal 2 : "<<endl;
    levelOrder2(root);
    return 0;
}