#include<bits/stdc++.h>
using namespace std;

// approach 2 (using min heap) TC: O(nlogk)
// Algorithm
// Insert the first k elements into a min heap.
// Traverse the remaining elements.
// If the current element is greater than the heap's top:
// Remove the top.
// Insert the current element.
// At the end, heap.top() is the kth largest element.
int kth_largest(vector<int> &arr, int e, int k){ 
    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    // step 1
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    // step 2
    for(int i=k;i<=e;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // step 3
    int ans = pq.top();
    return ans;

}
int main(){
    vector<int> arr = {7,2,4,9,1,5};
    // return 3 largest element
    cout<<"Approach 2 : "<<kth_largest(arr,5,3);
}