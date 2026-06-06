#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int value = this->data;
        // memory free
        while(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free from node with data "<<value<<endl;
    }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    // insert at start
    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    // inserting at last ppsition
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int position){
    // delete first or start node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        // deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        // if deleting last node
        if(curr == tail){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    // insertAtHead(head, 12);
    insertAtTail(tail, 12);
    print(head);
    // insertAtHead(head,15);
    insertAtTail(tail,15);
    print(head);
    insertAtPosition(head,tail,3,20);
    insertAtPosition(head,tail,4,40);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    deleteNode(head,tail,3);
    deleteNode(head,tail,4);

    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
}