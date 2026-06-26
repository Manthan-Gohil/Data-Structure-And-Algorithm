// transform tree nodes in which each node is the sum of its value + leftSubtree sum + right subTree sum
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

int sumTree(Node* root){
    if(root == NULL) return 0;

    int leftSubTreeSum = sumTree(root->left);
    int rightSubTreeSum = sumTree(root->right);
    
    root->data += leftSubTreeSum + rightSubTreeSum;

    return root->data;

}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1,2,,-1,-1,3,4,-1,-1,5,-1,-1
    cout<<"Level order traversal: "<<endl;
    levelOrderTraversal(root);
    
    sumTree(root);

    cout << "After transformation:\n";
    levelOrderTraversal(root);
    
}
