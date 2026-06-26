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
    cout<<"Enter data"<<endl;
    cin>>data;
    
    if(data == -1) return NULL;
    root = new Node(data);

    cout<<"Enter the left node for data : "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right node for data : "<<data<<endl;
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

// method 1 zig zag traversal using iterative level order TC O(N) SC O(N) 
vector<int> zig_zag_traversal(Node* root){
    queue<Node*> q;
    vector<int> result;
    if(root == NULL) return result;

    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        // level process
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToRight ? i : size-i-1;
            ans[index] = temp->data;
            
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        // direction change krni hai
        leftToRight = !leftToRight;

        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

    vector<int> result = zig_zag_traversal(root);
    for(auto num : result){
        cout<<num<<" ";
    }

}