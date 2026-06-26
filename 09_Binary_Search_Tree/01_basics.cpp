// binary search tree ->
// left sub tree node values are less than root node value
// right sub tree node values are greater than root node value


// inorder of BST is sorted
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

// TC : O(logn)
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

Node* minValue(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxValue(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    take_input(root);
    // 10,8,21,7,27,5,4,3,-1

    cout<<"Printing the BST : "<<endl;
    levelOrderTraversal(root);

    cout<<"Pre order : "<<endl;
    preOrder(root);
    cout<<endl;
    
    cout<<"In order : "<<endl;
    inOrder(root);
    cout<<endl;
    
    cout<<"Post order : "<<endl;
    postOrder(root);
    cout<<endl;
    
    
    cout<<"min value of BST : "<<minValue(root)->data<<endl;
    cout<<"max value of BST : "<<maxValue(root)->data<<endl;
    return 0;

}