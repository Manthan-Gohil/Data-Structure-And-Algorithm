// return maximum number of segments 
#include<bits/stdc++.h>
using namespace std;

int solve(int n, int &x, int &y, int &z){
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    int a = solve(n-x,x,y,z)+1;
    int b = solve(n-y,x,y,z)+1;
    int c = solve(n-z,x,y,z)+1;

    int ans = max(a, max(b,c));
    return ans;
}

// approach 1 pure recursive 
int cutSegments(int n, int x, int y, int z){
    int ans = solve(n,x,y,z);
    if(ans < 0) return 0;
    return ans;
}
int solveMem(int n, int x, int y, int z, vector<int> &dp){
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;


    if(dp[n] != -1){
        return dp[n];
    }
    int a = solveMem(n-x,x,y,z,dp)+1;
    int b = solveMem(n-y,x,y,z,dp)+1;
    int c = solveMem(n-z,x,y,z,dp)+1;

    dp[n] = max(a, max(b,c));
    return dp[n];
}

// approach 2 recursion + memoization
int cutSegments2(int n, int x, int y, int z){
    vector<int> dp(n+1,-1);
    int ans = solveMem(n,x,y,z,dp);
    if(ans < 0) return 0;
    return ans;
}

// approach 3 tabulation method
int cutSegments3(int n, int x, int y, int z){
    vector<int> dp(n+1, INT_MIN);

    dp[0] = 0;

    for(int i=1;i<=n;i++){
        if(i-x >= 0){
            dp[i] = max(dp[i], dp[i-x]+1);
        }
        if(i-y >= 0){
            dp[i] = max(dp[i], dp[i-y]+1);
        }
        if(i-z >= 0){
            dp[i] = max(dp[i], dp[i-z]+1);
        }
    }

    if(dp[n] < 0) return 0;
    else return dp[n];
}

int main(){
    int n = 8;
    cout<<"Recursive approach : "<<cutSegments(n,3,3,3)<<endl;
    cout<<"top down approach : "<<cutSegments2(n,2,3,5)<<endl;
    cout<<"bottom up approach : "<<cutSegments3(n,2,3,5)<<endl;
}