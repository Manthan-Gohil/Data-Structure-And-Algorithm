#include<bits/stdc++.h>
using namespace std;

// approach 1. (Recursive method) TC O(N) SC O(N)
int solve(vector<int> &cost, int n){
    if(n == 0){
        return cost[0];
    }
    if(n == 1){
        return cost[1];
    }

    int ans = min(solve(cost,n-1), solve(cost,n-2)) + cost[n];
    return ans;
}

int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    int ans = min(solve(cost,n-1), solve(cost,n-2));
    return ans;
}

// approach 2. (top-down approach recursion+memoization) TC O(N) SC O(N)
int solve2(vector<int> &cost, int n, vector<int> &dp){
    // base case
    if(n == 0){
        return cost[0];
    }
    if(n == 1){
        return cost[1];
    }
    // step 3
    if(dp[n] != -1) return dp[n];

    // step 2
    dp[n] = min(solve2(cost,n-1,dp), solve2(cost,n-2,dp)) + cost[n];
    return dp[n];
}

int minCostClimbingStairs2(vector<int> &cost){
    int n = cost.size();
    // step 1
    vector<int> dp(n+1,-1);
    int ans = min(solve(cost,n-1), solve(cost,n-2));
    return ans;
}

// approach 3. (bottom-up approach tabular) TC O(n) SC O(N)
int minCostClimbingStairs3(vector<int> &cost){
    int n = cost.size();
    // step 1 creation of dp array
    vector<int> dp(n+1);
    // step 2 base case analysis
    dp[0] = cost[0];
    dp[1] = cost[1];

    // step 3
    for(int i=2;i<n;i++){
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}

// approach 4. (bottom-up approach space optimized) TC O(n) SC O(1)
int minCostClimbingStairs4(vector<int> &cost){
    int n = cost.size();
 
    int prev1 = cost[1];
    int prev2 = cost[0];

    // step 3
    for(int i=2;i<n;i++){
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1,prev2);
}

int main(){
    vector<int> cost = {10,15,20};

    cout<<"Recursive method : "<<minCostClimbingStairs(cost)<<endl;
    cout<<"top-down method : "<<minCostClimbingStairs2(cost)<<endl;
    cout<<"bottom-up method : "<<minCostClimbingStairs3(cost)<<endl;
    cout<<"bottom-up method space optimized : "<<minCostClimbingStairs4(cost)<<endl;
}