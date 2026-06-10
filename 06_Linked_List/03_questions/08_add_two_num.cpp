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
    if(head == NULL) return;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// step1 reverse both linked list
// step 2 add linked list and store in ans list
// step 3 reverse the ans list

Node* add(Node* first, Node* second){
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        if(first != NULL){
            val1 = first->data;
        }
        int val2 = 0;
        if(second != NULL){
            val2 = second->data;
        }
        int sum = carry + val1 + val2;
        int digit = sum % 10;

        // create a node and add ans in linked list
        insertAtTail(ansHead,ansTail,digit);

        carry = sum/10;
        if(first != NULL)
            first = first->next;
        if(second != NULL)
            second = second->next;
        }
        return ansHead;
}

Node* reverse(Node* &head){
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* addTwoList(Node* &first, Node* &second){
    // step 1 reverse both linked list
    first = reverse(first);
    second = reverse(second);

    // step 2 add both linked list
    Node* ans = add(first, second);

    // step 3 reverse ans linked list
    ans = reverse(ans);
    return ans;
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(head1, tail1, 3);
    insertAtTail(head1, tail1, 4);
    insertAtTail(head1, tail1, 9);
    print(head1);
    insertAtTail(head2, tail2, 5);
    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 1);
    print(head2);

    Node* ans = addTwoList(head1, head2);
    while(ans != NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }


}