// three types of questions
// 1. detect cycle in linked list
// 2. remove cycle in linked list
// 3. beginning/ start node of the loop in linked list
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
    }else{
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

// detect loop (method 1)
bool detectLoop(Node* &head){
    if(head == NULL){
        return false;
    }
    Node* temp = head;
    map<Node*,bool> visited;

    while(temp != NULL){
        if(visited[temp]  == true){
            cout<<"cycle is present at node "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// detect loop (method 2) floyd cycle detection TC O(N) SC O(1) 
Node* Floyd_Detect_Loop(Node* &head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            cout<<"loop is present "<<endl;
            return slow;
        }
    }
    return NULL;
}

// beginning/ start node of loop linked list (floyd cycle detection algo)
Node* startNodeDetect(Node* &head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = Floyd_Detect_Loop(head);
    if(intersection == NULL)
        return NULL;
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    cout<<"start node is "<<slow->data<<endl;
    return slow;
}

// remove loop in linked list (need start node of linked list first)
void removeLoop(Node* &head){
    Node* startNode = startNodeDetect(head);
    Node* temp = startNode;
    while(temp->next != startNode){
        temp = temp->next;
    }
    temp->next = NULL;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    // print(head);
    tail->next = head->next;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    // if(detectLoop(head)){
    //     cout<<"cycle is present"<<endl;
    // }else{
    //     cout<<"cycle is not present"<<endl;
    // }

    // detect loop
    // cout<<Floyd_Detect_Loop(head)<<endl;


    // start node of loop
    // cout<<startNodeDetect(head)<<endl;

    // remove loop in linked list
    removeLoop(head);
    print(head);
}