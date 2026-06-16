// Queue -> FIFO (front and rear end)
// operations = 
// 1. push (add from the rear end) ->enqueue
// 2. pop  (remove from front end) - dequeue
// 3. front operation 
// each operation take TC(O(1))

// implement queue using linked list
// front -> head of the linked list head->data
// push -> insert data at tail of linked list
// pop -> delete the head node and head = head->next
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

class Queue{
    Node* head;
    Node* tail;
    
    public:
    Queue(){
        head = tail = NULL;
    }

    void push(int value){ // insert value at tail
        if(empty()){
            Node* temp = new Node(value);
            head = tail = temp;
        }
        else{
            Node* temp = new Node(value);
            tail->next = temp;
            tail = temp;
        }
    }

    void pop(){ // head  = head->next;
        if(empty()){
            cout<<"Queue is already empty"<<endl;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }

    }

    int front(){
        if(empty()){
            return -1;
        }
        else{
            return head->data;
        }

    }

    bool empty(){
        return head == NULL;
    }


};

int main(){
    Queue q;
    // queue<int> q; // using stl implementation
    q.push(1);
    q.push(2);
    q.push(3); // 1, 2, 3

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}

// difference between dequeue and deque
// dequeue is a pop operation in the queue
// deque is a double ended queue (new queue) where 
    // push operation can be done in both front and rear end 
    // pop operation can be done in both front and rear end
    // there is two operation front() and back() operation
    