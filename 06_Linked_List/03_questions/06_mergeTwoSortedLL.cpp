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
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
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

Node* solve(Node* first, Node* second){

    // if first list have only one node, point its next to entire second list
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){

        if((curr1->data <= curr2->data) && (curr2->data <= next1->data)){
            // add node in between the node of first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // updating pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            // move ahead of pointers
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* mergeSortedLL(Node* first, Node* second){
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }

    if(first->data <= second->data){
        return solve(first,second);
    }else{
        return solve(second, first);
    }
}

int main(){
    Node* first = NULL;
    Node* second = NULL;

    Node* tail1 = NULL;
    Node* tail2 = NULL;

    insertAtTail(first,tail1,2);
    insertAtTail(first,tail1,4);
    insertAtTail(first,tail1,6);
    insertAtTail(second,tail2,1);
    insertAtTail(second,tail2,3);
    insertAtTail(second,tail2,5);

    cout<<"List 1 : "<<endl;
    print(first);
    cout<<"List 2 : "<<endl;
    print(second);

    Node* result = mergeSortedLL(first, second);
    while(result != NULL){
        cout<<result->data<<" ";
        result = result->next;
    }


}