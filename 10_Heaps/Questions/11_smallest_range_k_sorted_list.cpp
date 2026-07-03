#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data, int r, int c){
        this->data = data;
        this->row = r;
        this->col = c;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

// TC : O((N*K) log K)
int kSorted(vector<vector<int>> &a, int k, int n){
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node*, vector<Node*>,compare> minHeap;

    // ztep 1 : create a min heap for starting element of each list and tracking mini/maxi values
    for(int i=0;i<k;i++){
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element,i,0));
    }

    int start = mini, end = maxi;

    // process ranges
    while(!minHeap.empty()){
        // mini fetch
        Node* top = minHeap.top();
        minHeap.pop();
        mini = top->data;

        // range or ans updation
        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }
        // next element exist
        if(top->col + 1 < n){
            maxi = max(maxi, a[top->row][top->col+1]);
            minHeap.push(new Node(a[top->row][top->col+1], top->row, top->col+1));
        }else{
            // next element does not exist
            break;
        }
    }
    // returning the difference of range value
    return (end-start+1);
}

int main() {

    vector<vector<int>> a = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}
    };

    int k = a.size();
    int n = a[0].size();

    cout << "Smallest Range Length = "
         << kSorted(a, k, n);

    return 0;
}