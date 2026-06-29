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

bool Two_Sum_BST(Node* root, int key){
    vector<int> inorderVal;

    inorder(root, inorderVal);

    // two pointer
    int i=0;
    int j = inorderVal.size()-1;
    while(i<j){
        int sum = inorderVal[i]+inorderVal[j];
        if(sum == key){
            return true;
        }
        else if(sum < key){
            i++;
        }
        else{
            j--;
        }
    }
    return false;

}

int main(){
    Node* root = NULL;
    cout<<"Build BST : "<<endl;
    // 5,4,8,2,6,10,3,7
    take_input(root);

    cout<<"level order traversal : "<<endl;
    levelOrderTraversal(root);

    cout<<"having two values that has sum = target value : "<<Two_Sum_BST(root,2)<<endl;

}