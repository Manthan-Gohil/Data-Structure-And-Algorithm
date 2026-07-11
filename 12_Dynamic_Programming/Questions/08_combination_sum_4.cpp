#include<bits/stdc++.h>
using namespace std;

// approach 1 (pure recursion)
int solve(vector<int> &nums ,int tar){
    // base case
    if(tar < 0) return 0;
    if(tar == 0) return 1;

    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans += solve(nums, tar-nums[i]);
    }
    return ans;
}

// approach 2 recursion + memoization
int solveMem(vector<int> &nums, int tar, vector<int> &dp){
    int n = nums.size();
    // base case
    if(tar < 0) return 0;
    if(tar == 0) return 1;

    if(dp[tar] != -1) return dp[tar];

    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans += solveMem(nums, tar-nums[i],dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

int findWays(vector<int> &nums, int tar){
    vector<int> dp(tar+1,-1);
    return solveMem(nums,tar,dp);
}

// approach 3 (tabular)
int solveTab(vector<int> &nums, int tar){
    vector<int> dp(tar+1,0);
    dp[0] = 1;

    // traversing from target 1 to tar
    for(int i=1;i<=tar;i++){
        // traversing on num vector
        for(int j=0;j<nums.size();j++){
            if(i-nums[j] >=0)
            dp[i] += dp[i-nums[j]];
        }
    }
    return dp[tar];
}

int main(){

    vector<int> nums = {1,2};

    cout<<"no of ways to get sum equals target (pure recursion) : "<<solve(nums,3)<<endl;
    cout<<"no of ways to get sum equals target (rec+mem) : "<<findWays(nums,3)<<endl;
    cout<<"no of ways to get sum equals target (tabular) : "<<solveTab(nums,3)<<endl;
}