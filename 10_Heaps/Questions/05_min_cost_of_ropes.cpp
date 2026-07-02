// Minimum Cost of ropes
// There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.
#include<bits/stdc++.h>
using namespace std;

int min_cost_ropes(vector<int> &nums, int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(nums[i]);
    }
    int cost = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

int main(){
    vector<int> nums = {4,3,2,6};
    cout<<"Minimum cost of ropes : "<<min_cost_ropes(nums, 4)<<endl;
}