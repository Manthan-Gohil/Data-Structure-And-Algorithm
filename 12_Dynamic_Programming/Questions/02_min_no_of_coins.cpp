#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int x){
    // base case
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0;i<nums.size();i++){
        int ans = solve(nums,x-nums[i]);
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    return mini;
}
// method 1 pure recursion (TC O(n^x) SC O(x))
int minimumElements(vector<int> &nums, int x){
    int ans = solve(nums,x);
    if(ans == INT_MAX) return -1;
    return ans;
}

// method 2 recursion + memoization (TC O(n*x) SC O(x))
int solveMem(vector<int> &nums, int x, vector<int> &dp){
    // base case
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return INT_MAX;
    }

    if(dp[x] != -1){
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0;i<nums.size();i++){
        int ans = solve(nums,x-nums[i]);
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    dp[x] = mini;
    return mini;   
}


// method 3 tabular method (TC O(n*x) SC O(x))
int solveTab(vector<int> &nums, int x){
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=x;i++){
        for(int j=0;j<nums.size();j++){
            if(i-nums[j] >= 0 && dp[i-nums[j]] != INT_MAX){
                dp[i] = min(dp[i],1+dp[i-nums[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX) return -1;
    return dp[x];
}
int main(){
    vector<int> nums = {1,2,3};

    int x = 7;
    cout<<"Recursive method = "<<minimumElements(nums,x)<<endl;

    // method 2
    vector<int> dp(x+1,-1);
    int ans = solveMem(nums,x,dp);
    if(ans == INT_MAX) return -1;
    else cout<<"Top down approach : "<<ans<<endl;

    cout<<"Tabular method : "<<solveTab(nums,x)<<endl;

}