// max sum of non-adjacent elements
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int n){
    // moving array from right to left

    // base case
    if(n < 0) return 0;
    if(n == 0) return nums[0];

    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1) + 0;

    return max(incl,excl);
}

// method 1 pure recursive approach
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int ans = solve(nums, n-1);
    return ans;
}

int solveMem(vector<int> &nums, int n, vector<int> &dp){
    // moving array from right to left

    // base case
    if(n < 0) return 0;
    if(n == 0) return nums[0];

    if(dp[n] != -1){
        return dp[n];
    }
    int incl = solveMem(nums,n-2,dp) + nums[n];
    int excl = solveMem(nums,n-1,dp) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}

// method 2 recursive + memoization
int maximumNonAdjacentSum2(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solveMem(nums, n-1, dp);
}

// method 3 tabular method
int maximumNonAdjacentSum3(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);

    dp[0] = nums[0];

    for(int i=1;i<n;i++){
        int incl = nums[i];
        if(i > 1){
            incl += dp[i-2];
        }
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }
    return dp[n-1];
}
// method 4 tabular method (space optimized)
int maximumNonAdjacentSum4(vector<int> &nums){
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1;i<n;i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int main(){

    vector<int> nums = {1,2,3,4};

    cout<<"Recursive approach : "<<maximumNonAdjacentSum(nums)<<endl;
    cout<<"Top down approach : "<<maximumNonAdjacentSum2(nums)<<endl;
    cout<<"Bottom up approach : "<<maximumNonAdjacentSum3(nums)<<endl;
    cout<<"Bottom up approach (space optimized) : "<<maximumNonAdjacentSum4(nums)<<endl;

}