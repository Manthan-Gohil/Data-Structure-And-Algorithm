#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout<<"Enter data : "<<endl;
    cin>>data;

    root = new Node(data);

    if(data == -1) return NULL;

    cout<<"Enter the left node data for "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right node data for "<<data<<endl;
    root->right = buildTree(root->right);

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
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}
int maxSum;
int solve(Node* root){
    if(root == NULL) return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    int neeche_hi_milgaya_ans = l + r + root->data;

    int koi_ek_acha = max(l,r) + root->data;

    int only_root_acha = root->data;

    maxSum = max({maxSum, neeche_hi_milgaya_ans, koi_ek_acha, only_root_acha});

    // sabse important part
    return max(koi_ek_acha,only_root_acha);
}

int max_path_sum(Node* root){
    maxSum = INT_MIN;

    solve(root);

    return maxSum;
}

int main(){

    Node* root = NULL;
    root = buildTree(root);

    cout<<"max path sum : "<<max_path_sum(root);

}