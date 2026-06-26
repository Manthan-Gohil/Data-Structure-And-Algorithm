// diameter = longest path between any two nodes (i.e, nnumber of nodes between these)
// TC O(N) SC O(MAX HEIGHT)
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

pair<int,int> diameterFast(Node* root){
    // first pair store the diameter and second will store the height
    if(root == NULL){
        pair<int,int> p = {0,0};
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + 1 + right.second;

    pair<int,int> ans;
    ans.first = max(max(opt1, opt2), opt3); // store diameter
    ans.second = max(left.second, right.second) + 1; // store height
    
    return ans;
} 

int diameter(Node* root){
    return diameterFast(root).first;
}
int main(){
    Node* root = NULL;
    // 1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, 9, 8, -1, -1, -1, -1
    root = buildTree(root);
    levelOrderTraversal(root);

    cout<<"Diameter : "<<diameter(root)<<endl;
    
}