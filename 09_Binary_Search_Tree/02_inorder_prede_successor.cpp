#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void findPredSucc(Node* root, Node* &pred, Node* &succ, int key){

    if(root == NULL)
        return;

    // Found the key
    if(root->data == key){

        // predecessor
        if(root->left){
            Node* temp = root->left;

            while(temp->right){
                temp = temp->right;
            }

            pred = temp;
        }

        // successor
        if(root->right){
            Node* temp = root->right;

            while(temp->left){
                temp = temp->left;
            }

            succ = temp;
        }

        return;
    }

    // Key is smaller
    if(key < root->data){
        succ = root;                 // possible successor
        findPredSucc(root->left, pred, succ, key);
    }

    // Key is greater
    else{
        pred = root;                 // possible predecessor
        findPredSucc(root->right, pred, succ, key);
    }
}