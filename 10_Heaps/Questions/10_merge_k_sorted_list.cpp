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

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

// TC : O(n*klog(k)) SC: O(k)
Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    int k = listArray.size();

    if(k == 0) return NULL;

    for(int i=0;i<k;i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(!minHeap.empty()){
        Node* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL){
            minHeap.push(top->next);
        }

        if(head == NULL){
            head = top;
            tail = top;
        }
        else{
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // List 1 : 1 -> 4 -> 5
    Node* head1 = new Node(1);
    head1->next = new Node(4);
    head1->next->next = new Node(5);

    // List 2 : 1 -> 3 -> 4
    Node* head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(4);

    // List 3 : 2 -> 6
    Node* head3 = new Node(2);
    head3->next = new Node(6);

    vector<Node*> listArray;

    listArray.push_back(head1);
    listArray.push_back(head2);
    listArray.push_back(head3);

    Node* ans = mergeKLists(listArray);

    cout << "Merged List : ";
    print(ans);

    return 0;
}