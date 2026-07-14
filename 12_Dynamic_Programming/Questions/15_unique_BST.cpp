// also known as catlan problem
#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    // base case
    if(n <=1) return 1;

    int ways = 0;
    for(int root = 1;root<=n;root++){
        ways += solve(root-1)*solve(n-root);
    }
    return ways;
}
// approach 1 (pure recursion)
int uniqueBST(int n){
    return solve(n);
}

int solveMem(int n, vector<int> &dp){
    // base case
    if(n <=1) return 1;

    if(dp[n] != -1) return dp[n];
    int ways = 0;
    for(int root = 1;root<=n;root++){
        ways += solveMem(root-1,dp)*solveMem(n-root,dp);
    }
    dp[n] = ways;
    return dp[n];
}

// approach 2 top-down
int uniqueBST2(int n){
    vector<int> dp(n+1,-1);
    return solveMem(n,dp);
}

// approach 3 (bottom-up)
int uniqueBST3(int n){
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        for(int root=1;root<=i;root++){
            dp[i] += dp[root-1]*dp[i-root];
        }
    }
    return dp[n];

}
int main(){
    cout<<"Unique BST : (pure recursion) "<<uniqueBST(3)<<endl;
    cout<<"Unique BST : (top-down) "<<uniqueBST2(3)<<endl;
    cout<<"Unique BST : (bottom-up) "<<uniqueBST3(3)<<endl;
}