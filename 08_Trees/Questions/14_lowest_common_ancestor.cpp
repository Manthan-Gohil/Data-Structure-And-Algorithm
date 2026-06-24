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
// helper function (not needed in leetcode just for verifying)
Node* findNode(Node* root, int val){
    if(root == NULL) return NULL;

    if(root->data == val) return root;

    Node* left = findNode(root->left, val);
    if(left) return left;

    return findNode(root->right, val);
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root == NULL) return NULL;

    if(root->data == p->data || root->data == q->data){
        return root;
    }

    Node* leftLCA = lowestCommonAncestor(root->left, p, q);
    Node* rightLCA = lowestCommonAncestor(root->right, p,q);

    if(leftLCA && rightLCA){
        return root;
    }
    else if(leftLCA!= NULL){
        return leftLCA;
    }else{
        return rightLCA;
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1,2,4,-1,-1,5,8,-1,-1,9,-1,-1,3,6,-1,-1,7,-1,-1
    cout<<"Level Order Traversal : "<<endl;
    levelOrderTraversal(root);

    int x = 4, y = 9;

    Node* p = findNode(root, x);
    Node* q = findNode(root, y);

    Node* lca = lowestCommonAncestor(root, p, q); // 2 is the ans of 4 and 9

    if(lca){
        cout << "\nLCA of " << x << " and " << y << " is "
            << lca->data << endl;
    }

}