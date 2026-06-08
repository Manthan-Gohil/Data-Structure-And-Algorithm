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
    if(head == NULL){
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// method 1
void sort_0_1_2(Node* &head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }
        else if(temp->data == 1){
            oneCount++;
        }
        else if(temp->data == 2){
            twoCount++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
}

void populate(Node* &tail, Node* curr){
    tail->next = curr;
    tail = curr;
}

// method 2 (without replacing data in LL)
void sort_012(Node* &head){
    // create dummy pointers
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    // create separate list 0, 1, 2
    while(curr != NULL){
        if(curr->data == 0){
            populate(zeroTail, curr);
        }
        else if(curr->data == 1){
            populate(oneTail, curr);
        }
        else if(curr->data == 2){
            populate(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 sublist
    // 1s list not empty
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        // 1s list empty
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    print(head);
    // sort_0_1_2(head);
    sort_012(head);
    cout<<"After sorting : "<<endl;
    print(head);

}