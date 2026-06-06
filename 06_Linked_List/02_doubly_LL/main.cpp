// in doubly linked list, each node is having data and two pointers prev and next, pointing to previous node and next node
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int value = this->data;
        while(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory free from node with data "<<value<<endl;
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
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int len(Node* &head){
    if(head == NULL){
        return 0;
    }else{
        Node* temp = head;
        int cnt = 1;
        while(temp != NULL){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    // adding start node
    if(position == 1){
        insertAtHead(head, tail,d);
        return;
    }
    else{
        Node* temp = head;
        int cnt = 1;
        while(cnt < position-1){
            temp = temp->next;
            cnt++;
        }
        // inserting at last ppsition
        if(temp->next == NULL){
        insertAtTail(head,tail, d);
        return;
        }

        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        nodeToInsert->prev = temp;
        temp->next = nodeToInsert;
    }
}

void deleteNode(Node* &head, Node* &tail, int position){
    // deleting start node
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if(curr == tail){
            tail = prev;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout<<len(head)<<endl;

    insertAtHead(head, tail, 10);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtHead(head, tail, 20);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtHead(head, tail, 30);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtTail(head, tail, 40);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtPosition(head, tail, 2, 50);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtPosition(head, tail, 1, 101);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    insertAtPosition(head, tail, 7, 103);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    deleteNode(head, tail, 5);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    deleteNode(head, tail, 6);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
}    