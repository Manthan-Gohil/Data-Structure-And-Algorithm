// balanced BST is tree in which abs(height[left] - height[right]) <=1
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

void inorder(Node* root, vector<int> &in){
    if(root == NULL) return;

    // LNR
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right,in);
}

Node* inorderToBST(int s, int e, vector<int> &nums){
    // base case
    if(s > e) return NULL;

    int mid = (s+e)/2;

    Node* root = new Node(nums[mid]);
    root->left = inorderToBST(s,mid-1,nums);
    root->right = inorderToBST(mid+1,e,nums);
    return root;
}

Node* Balanced_BST(Node* root){
    vector<int> inorderVal;
    inorder(root, inorderVal);

    int n = inorderVal.size();
    return inorderToBST(0,n-1,inorderVal);
}

int main(){
    Node* root = NULL;
    cout<<"Build BST : "<<endl;
    // 5,4,8,2,6,10,3,7
    take_input(root);

    cout<<"level order traversal : "<<endl;
    levelOrderTraversal(root);

    Node* newRoot = Balanced_BST(root);
    cout<<"level order traversal of balanced BST : "<<endl;
    levelOrderTraversal(newRoot);

}