// given a binary tree, find if it is height balanced or not. A tree is height balanced if difference between height of left and right subtree is not more than one for all the nodes of tree
// height[left] - height[right] <= 1
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
    cout<<"Enter data : "<<ends;
    cin>>data;

    if(data == -1) return NULL;
    root = new Node(data);

    cout<<"Enter the left node data for : "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right node data for : "<<data<<endl;
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
// method 1 -> using height formula
int height(Node* root){
    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;

    return ans;
}


// TC O(N2)
bool isBalanced(Node* root){
    if(root == NULL) return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff){
        return 1;
    }
    else{
        return false;
    }
}

// method 2 -> using pairs to store isBalanced and height both 
// TC O(N)
pair<bool,int> isBalancedFast(Node* root){
    if(root == NULL){
        pair<bool,int> p = {true,0};
        return p;
    }

    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool,int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(left.second,right.second) + 1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}

bool isBalanced2(Node* root){
    return isBalancedFast(root).first;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1, 10, 5, -1,-1,-1,39,-1,-1 = balanced
    // 1,10,5,-1,-1,-1,-1 = unbalanced
    levelOrderTraversal(root);

    cout<<"is balanced " <<isBalanced(root);

    cout<<"is balanced "<<isBalanced2(root);

}