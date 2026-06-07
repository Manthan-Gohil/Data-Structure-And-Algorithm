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

void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int d){
    if(tail == NULL){
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
    if(head == NULL){
        return;
    }
    else{
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

// reverse a linked list (O(n))
Node* reverseLL(Node* &head, Node* &tail){
    if(head == NULL || head->next == NULL){
        return head;
    }
    else{
        Node* oldHead = head; // for updating head and tail (not required)
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;

        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev; // updating head (not required)
        tail = oldHead; // updating tail (not required)
        return prev;
    }
}

// recursive method  tc O(n) sc O(n)
Node* reverseLL2(Node* head){ // i can not reverse heaad and tail using this recursive function for updating it using main function
    // base case
    if(head == NULL || head->next == NULL){
        return head;
    }
  
        Node* newHead = reverseLL2(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    // Node* result = reverseLL(head, tail);
    Node* result = reverseLL2(head);

    while(result != NULL){
        cout<<result->data<<" ";
        result = result->next;
    }
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

}