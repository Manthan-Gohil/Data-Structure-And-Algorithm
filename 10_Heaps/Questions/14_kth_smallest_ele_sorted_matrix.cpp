#include<bits/stdc++.h>
using namespace std;

class Solution {
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
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Node*, vector<Node*>,compare> minHeap;
        int k_row = matrix.size();
        for(int i=0;i<k_row;i++){
            int element = matrix[i][0];
            minHeap.push(new Node(element,i,0));
        }

        int count = 0;
        int answer;
        while(count != k){
            Node* top = minHeap.top();
            minHeap.pop();
            answer = top->data;
            count++;

            if(top->col + 1 < matrix[0].size()){
                minHeap.push(new Node(matrix[top->row][top->col+1],top->row,top->col+1));
            }
        }
        return answer;
    }
};