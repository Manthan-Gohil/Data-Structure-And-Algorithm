// linked list
// linked list is a type of linear data structure which has the collection of nodes
// each node is having a data and address of the next node (using pointers)

// why linked list?
// in array, size can not be changed at run time
// vector is dynamic array but while size of verctor is full then after adding one more element in vector, it just double its capacity in vector (new storage + value copy) which is not optimal

// advantage of linked list
// dynamic data structure (grow & shrik at runtime that's why no memory wastage)
// insertion/deletion -> easy (no shift needed)

// types of linked list
// 1. singly linked list
// 2. doubly linked list
// 3. circular linked list
// 4. circular doubly linked list

// singly linked list -> each node is having one data members and one pointer which point address to the next node

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
};

int main(){
    Node* node1 = new Node(10); // node1 is NOT the node.It is a pointer that stores the address of the node.
    cout<<node1->data<<endl; // (*node1).data
    cout<<node1->next<<endl;

}
