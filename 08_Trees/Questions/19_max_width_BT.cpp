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
    cout<<"Enter data : "<<endl;
    int data;
    cin>>data;

    if(data == -1) return NULL;
    root = new Node(data);

    cout<<"Enter the data for left node for : "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right node for : "<<data<<endl;
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
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int widthOfBinaryTree(Node* root){
    queue<pair<Node*,unsigned long long>> q;
    q.push({root,0});
    int maxWidth = 0;

    while(!q.empty()){
        int size = q.size();
        unsigned long long stIdx = q.front().second;
        unsigned long long endIdx = q.back().second;

        maxWidth = max(maxWidth, (int)(endIdx-stIdx+1));

        for(int i=0;i<size;i++){
            auto temp = q.front();
            q.pop();

            if(temp.first->left){
                q.push({temp.first->left, temp.second*2+1});
            }
            if(temp.first->right){
                q.push({temp.first->right, temp.second*2+2});
            }
        }
    }
    return maxWidth;
}

int main(){

    Node* root = NULL;
    root = buildTree(root);

    cout<<"Level Order Traversal : "<<endl;
    levelOrderTraversal(root);

    cout<<"Max width of tree : "<<widthOfBinaryTree(root)<<endl;

}