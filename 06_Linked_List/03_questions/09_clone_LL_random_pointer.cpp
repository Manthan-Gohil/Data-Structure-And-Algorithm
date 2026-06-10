#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// method 1  TC(O(n)) SC(O(n))
// step 1 clone a linked list using next pointer (ignore the random pointer)
// step 2 create  a map function and store the nodes of original node and clone node and map each other
// step 3 now initialize the random pointer of clonelist using map[originallist->random]
Node* cloneList(Node* &head){
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;

    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 create a map
    unordered_map<Node*, Node*> oldToNew;
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while(originalNode != NULL && cloneNode!= NULL){
        oldToNew[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // step 3
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL){
        cloneNode->random = oldToNew[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

// method 2 (remove map) TC(O(n)) SC(O(1))
// step 1 create a clone list
// step 2 clonenode add in between original list
// step 3 random pointer (temp->next->random = temp->random->next)
// step 4 revert changes done in step 2
// step 5 return ans (clonehead)
Node* cloneList2(Node* &head){
    // step 1 create a clone list

    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 cloneNodes add between original node
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // step 3 random pointer copy
    temp = head;

    while(temp != NULL){
        if(temp->next != NULL){
            if(temp->random != NULL){
                temp->next->random = temp->random->next;
            }else{
                temp->next = NULL; 
            }
        }
        temp = temp->next->next;
    }

    // step 4 revert changes done in step 2
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if(originalNode != NULL){
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }

    // step 5 return ans
    return cloneHead;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 7);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = tail;
    head->next->next->next->random = tail;
    tail->random = head->next->next;

    print(head);

    Node* ans = cloneList2(head);
    while(ans != NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    

}