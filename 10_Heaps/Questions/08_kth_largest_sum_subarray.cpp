#include<bits/stdc++.h>
using namespace std;

// approach 1 TC : O(n^2logn) SC O(n^2)
int kth_largest_sum_subarray(vector<int> &nums, int k){
    int n = nums.size();

    vector<int> sumStore;
    // all the subarray
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += nums[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size()-k];
}

// approach 2 mroe optimized using (minheap)  TC : O(n^2logk) 
int kth_largest_sum_subarray(vector<int> &nums, int k){
    int n =  nums.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += nums[j];
            if(pq.size() < k){
                pq.push(sum);
            }
            else{
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
int main(){
    vector<int> nums = {};

}