#include<bits/stdc++.h>
using namespace std;

// approach 1 TC : O(nlogn)
// sort the array then return the value at arr[k-1];
int kth_smallest(vector<int> &arr, int k){
    sort(arr.begin(), arr.end());
    return arr[k-1];
}

// approach 2 (using heap) TC: O(nlogk)
// 1 store first k element to heap
// then from the k index to n-1 check if element < heap.top()
// then delete the root and put this value
int kth_smallest_2(vector<int> &arr, int l, int e, int k){ // e will be size-1 index
    priority_queue<int> pq;

    // step 1
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    // step 2
    for(int i=k;i<=e;i++){
        if(arr[i]<pq.top()){
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
    // return the 3rd smallest element
    // cout<<"Approach 1 : "<<kth_smallest(arr,3);
    cout<<"Approach 2 : "<<kth_smallest_2(arr,0,5,3);
}