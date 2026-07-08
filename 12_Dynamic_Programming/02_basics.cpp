// question-> nth fibonacci number
#include<bits/stdc++.h>
using namespace std;

// TC O(n) SC O(n) 
// Approach 1. (using top-down approach)
int fab(int n, vector<int> &dp){
    // base case
    if(n <=1) return n;

    // step 3
    if(dp[n] != -1) return dp[n];   

    // step 2
    dp[n] = fab(n-1,dp) + fab(n-2,dp);
    return dp[n];
}

// Approach 2. (using bottom-up approach) TC O(n) SC O(n) 
int fab2(int n, vector<int> &dp){
    // step 2
    dp[0] = 0;
    dp[1] = 1;

    // step 3
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
// Approach 2. (using bottom-up approach with space optimized) TC O(n) SC O(1) 
// do not need to create the dp array
int fab3(int n){
    // step 2
    int prev1 = 1;
    int prev2 = 0;

    if(n == 0) return prev2;

    // step 3
    for(int i=2;i<=n;i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n;
    cin>>n;
    // step 1
    vector<int> dp(n+1,-1);


    cout<<"Approach 1 = "<<fab(n,dp)<<endl;
    cout<<"Approach 2 = "<<fab2(n,dp)<<endl;
    cout<<"Approach 2 (space optimized) = "<<fab3(n)<<endl;
}