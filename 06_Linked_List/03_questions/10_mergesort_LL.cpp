#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}

void print(Node* &head){
    if(head == NULL) return;
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* getMiddle(Node* &head){
    if(head == NULL || head->next == NULL) return head;
    Node* slow = head;
    Node* fast  = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* &left, Node* &right){
    if(left == NULL) return right;
    if(right == NULL) return left;

    // dummy node
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left->data <= right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

Node* mergeSort(Node* &head){
    if(head == NULL || head->next == NULL) return head;
    // step 1 find middle node
    Node* mid = getMiddle(head);
    // step 2 divide linked list into two equal halves
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    // step 3 merge both sorted linked list
    Node* ans = merge(left, right);
    return ans;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 80);
    insertAtTail(head, tail, 70);
    cout<<"before merge sort"<<endl;
    print(head);
    cout<<"after merge sort"<<endl;
    Node* ans = mergeSort(head);
    while(ans != NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }

}