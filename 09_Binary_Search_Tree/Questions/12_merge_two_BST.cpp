#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertToBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data < root->data){
        root->left = insertToBST(root->left,data);
    }
    else{
        root->right = insertToBST(root->right, data);
    }
    return root;
}

Node* take_input(Node* root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertToBST(root,data);
        cin>>data;
    }
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    if(root == NULL) return;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// approach 1. TC O(m+n) SC O(m+n)
// step 1 -> store both the BST into array in sorted order (inorder traversal)
// step 2 -> merge two sorted arrays
// step 3 -> convert mergedArray to BST (balanced BST)

void inorder(Node* root, vector<int> &in){
    if(root == NULL) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &bst1, vector<int> &bst2){
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i < bst1.size() && j < bst2.size()){
        if(bst1[i] < bst2[j]){
            ans.push_back(bst1[i]);
            i++;
        }
        else{
            ans.push_back(bst2[j]);
            j++;
        }
    }

    // remaining values
    while(i<bst1.size()){
        ans.push_back(bst1[i]);
        i++;
    }
    while(j<bst2.size()){
        ans.push_back(bst2[j]);
        j++;
    }
    return ans;
}

Node* arrayToBST(int s, int e, vector<int> &nums){
    // base case
    if(s > e) return NULL;

    int mid = (s+e)/2;

    Node* root = new Node(nums[mid]);
    root->left = arrayToBST(s,mid-1,nums);
    root->right = arrayToBST(mid+1,e,nums);
    return root;
}

Node* mergeBST(Node* root1, Node* root2){
    // step 1 make two array and store in sorted order 
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // step 2 merge two sorted array
    vector<int> mergedArray = mergeArrays(bst1, bst2);

    // step 3 convert merged array to balanced BST
    int s = 0;
    int e = mergedArray.size()-1;
    return arrayToBST(s,e,mergedArray);
}

// approach 2 (using doubly linked list) TC (m+n) SC O(height 1 + height 2) more optimized SC compared to approach 1
// step 1 -> convert both BST to sorted DLL
// step 2 -> merge two sorted DLL
// step 3 -> convert merged DLL to BST

void convertIntoSortedDLL(Node* root, Node* &head){
    // base case
    if(root == NULL) return;

    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;

    convertIntoSortedDLL(root->left, head);
}

Node* mergeLinkedList(Node* head1, Node* head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;

            }else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL){
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
    }
    while(head2 != NULL){
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
    }
    return head;
}

int countNodes(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* sortedLLToBST(Node* &head, int n){
    // base case
    if(n <= 0 || head == NULL) return NULL;

    Node* left = sortedLLToBST(head, n/2);
    
    Node* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n-n/2-1);
    return root;

}
Node* mergeBST2(Node* root1, Node* root2){
    // step 1 convert BST into sorted DLL
    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // step 2 merge sorted DLL
    Node* head = mergeLinkedList(head1, head2);

    // step 3 convert SLL into BST
    return sortedLLToBST(head, countNodes(head));
}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;
    // 5,4,8,2,6,10,3,7,-1
    cout<<"BST : "<<endl;
    root1 = take_input(root1);
    cout<<"level order traversal : "<<endl;
    levelOrderTraversal(root1);
    // 10,8,21,7,27,5,4,3,-1
    cout<<"BST : "<<endl;
    root2 = take_input(root2);
    cout<<"level order traversal : "<<endl;
    levelOrderTraversal(root2);

    cout<<"Final BST: "<<endl;
    Node* root3 = mergeBST(root1,root2);
    levelOrderTraversal(root3);
}