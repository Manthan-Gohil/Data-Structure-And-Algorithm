#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* bottom;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};

void print(Node* &head){
    if(head == NULL) return;
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->bottom;
    }
    cout<<endl;
}

Node* merge(Node* &left, Node* &right){
    if(left == NULL) return right;
    if(right == NULL) return left;

    // dummy node
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left->data <= right->data){
            temp->bottom = left;
            temp = left;
            left = left->bottom;
        }
        else{
            temp->bottom = right;
            temp = right;
            right = right->bottom;
        }
    }

    while(left != NULL){
        temp->bottom = left;
        temp = left;
        left = left->bottom;
    }
    while(right != NULL){
        temp->bottom = right;
        temp = right;
        right = right->bottom;
    }
    ans = ans->bottom;
    return ans;
}

Node* flatten(Node* root){
    if(root == NULL || root->next == NULL) return root;

    // flatten the remaining list
    root->next = flatten(root->next);

    // merge current list with flatten list
    root = merge(root, root->next);
    
    return root;
}

int main(){
     /*
        5 -> 10 -> 19 -> 28
        |     |      |      |
        7     20     22     35
        |            |      |
        8            50     40
        |                   |
        30                  45
    */

    Node* head = new Node(5);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Node* ans = flatten(head);
    while(ans != NULL){
        cout<<ans->data<<" ";
        ans = ans->bottom;
    }

}