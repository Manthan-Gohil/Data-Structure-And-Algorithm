#include<bits/stdc++.h>
using namespace std;

// approach 1 pure recursion
int countDerangement(int n){
    // base case
    if(n == 1) return 0;
    if(n == 2) return 1;

    int ans = (n-1)*(countDerangement(n-2) + countDerangement(n-1));
    return ans;
}

int solveMem(int n, vector<int> &dp){
    // base case 
    if(n == 1) return 0;
    if(n == 2) return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = (n-1)*(solveMem(n-2,dp) + solveMem(n-1,dp));

    return dp[n];
}

// approach 2 recursion + memoization
int countDerangement2(int n){
    vector<int> dp(n+1,-1);
    return solveMem(n, dp);
}

// approach 3 tabular method
int countDerangement3(int n){
    vector<int> dp(n+1,0);

    dp[1] = 0;
    dp[2] = 1;

    for(int i=3;i<=n;i++){
        int ans = (i-1)*(dp[i-1]+dp[i-2]);
        dp[i] = ans;
    }
    return dp[n];
}

// approach 4 space optimized 
int countDeragement4(int n){
    int prev2 = 0;
    int prev1 = 1;

    for(int i=3;i<=n;i++){
        int ans = (i-1)*(prev2 + prev1);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int main(){
    int n = 3;
    cout<<"Count derangement = "<<countDerangement(n)<<endl;
    cout<<"Count derangement(rec + mem) = "<<countDerangement2(n)<<endl;
    cout<<"Count derangement(tabular) = "<<countDerangement3(n)<<endl;
    cout<<"Count derangement(space optimized) = "<<countDerangement3(n)<<endl;

}