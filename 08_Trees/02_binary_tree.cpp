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
static int idx = -1;
Node* buildTree(vector<int> &preorder){
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    
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

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
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

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }

        cout<<curr->data<<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);
    cout<<root->data<<endl;
    
    cout<<"preorder traversal : ";
    preOrder(root);
    cout<<endl;
    cout<<"inorder traversal : ";
    inOrder(root);
    cout<<endl;
    cout<<"postorder traversal : ";
    postOrder(root);
    cout<<endl;
    cout<<"levelorder traversal : ";
    levelOrder(root);
    cout<<"levelorder traversal 2 : "<<endl;
    levelOrder2(root);
    return 0;
}