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
    if(head == NULL) return;
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
// method 1 (TC : O(n) SC : O(n))
bool isPalindrome(vector<int> &nums){
    int n = nums.size();
    int i = 0;
    int j = n-1;
    while(i<j){
        if(nums[i] != nums[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool checkPalindrome(Node* &head){
    vector<int> nums;
    Node* temp = head;
    while(temp != NULL){
        nums.push_back(temp->data);
        temp = temp->next;
    }
    if(isPalindrome(nums)){
        return true;
    }
    else{
        return false;
    }
}

// method 2 
// step 1 find middle(find)
// step 2 reverse nodes after middle
// step 3 compare both halves
// step 4 repeat second half (optional)
Node* getMiddle(Node* &head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
// method 2
bool isPalindrome2(Node* &head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    // step 1 find middle node
    Node* middle = getMiddle(head);

    // step 2 reverse list after middle
    Node* temp = middle->next;
    middle->next = reverse(temp);

    // step 3 compare both halves
    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // step 4 (optional)
    temp = middle->next; // optional
    middle->next = reverse(temp); // optional

    return true;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    // insertAtTail(head, tail, 1);
    print(head);

    // method 1
    cout<<"is Palindrome (method 1): "<<checkPalindrome(head)<<endl;

    // method 2
    cout<<"is palindrome (method 2): "<<isPalindrome2(head)<<endl;
}