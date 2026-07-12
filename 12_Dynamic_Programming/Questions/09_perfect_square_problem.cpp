// return minimum number of squares needed to make N
#include<bits/stdc++.h>
using namespace std;

int minSquare(int n){
    // base case
    if(n == 0) return 0;

    int ans = n;
    for(int i=1;i*i<=n;i++){
        ans = min(ans, 1+minSquare(n-i*i));
    }
    return ans;
}

int solveMem(int n,vector<int> &dp){
    // base case
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];
    int ans = n;
    for(int i=1;i*i<=n;i++){
        ans = min(ans,1+solveMem(n-i*i,dp));
    }
    dp[n] = ans;
    return dp[n];
}

int minSquare2(int n){
    vector<int> dp(n+1,-1);
    return solveMem(n,dp);
}

int minSquare3(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=n;j++){
            if(i-j*j>=0){
                dp[i] = min(dp[i],1+dp[i-j*j]);
            }
        }
    }
    return dp[n];
}

int main(){
    cout<<"Minimum number of squares (recursion) "<<minSquare(6)<<endl;
    cout<<"Minimum number of squares (recursion + memoization) "<<minSquare2(6)<<endl;
    cout<<"Minimum number of squares (tabulation) "<<minSquare3(6)<<endl;
}