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
    if(head == NULL || tail == NULL){
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
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* rotate_LL(Node* &head, int k){
    if(head == NULL || head->next == NULL){
        return head;
    }
    int L = 1;
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
        L++;
    }

    k = k%L;
    if(k == 0) return head;

    // connect tail to head
    tail->next = head;

    int remaining = L-k;
    Node* newTail = head;
    for(int cnt=1;cnt<remaining;cnt++){
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    print(head);

    cout<<"After rotating : "<<endl;
    Node* ans = rotate_LL(head,2);
    print(ans);



}