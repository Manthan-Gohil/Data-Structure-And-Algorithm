// question-> nth fibonacci number (using top-down approach)
#include<bits/stdc++.h>
using namespace std;

// TC O(n) SC O(n)
int fab(int n, vector<int> &dp){
    // base case
    if(n <=1) return n;

    // step 3
    if(dp[n] != -1) return dp[n];   

    // step 2
    dp[n] = fab(n-1,dp) + fab(n-2,dp);
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    // step 1
    vector<int> dp(n+1,-1);


    cout<<fab(n,dp)<<endl;
}