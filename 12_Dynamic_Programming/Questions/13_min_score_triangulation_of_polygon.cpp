#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int i, int j){
    // base case (if only two points exists then not form triangle)
    if(i+1 == j) return 0;

    int ans = INT_MAX;
    for(int k=i+1;k<=j-1;k++){
        ans = min(ans, v[i]*v[j]*v[k] + solve(v,i,k) + solve(v,k,j));
    }
    return ans;
}
// approach 1 (pure recursion)
int minScoreTriangulation(vector<int> &values){
    int n = values.size();
    return solve(values,0,n-1);
}

int solveMem(vector<int> &v, int i, int j, vector<vector<int>> &dp){
    // base case (if only two points exists then not form triangle)
    if(i+1 == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k=i+1;k<=j-1;k++){
        ans = min(ans, v[i]*v[j]*v[k] + solveMem(v,i,k,dp) + solveMem(v,k,j,dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
// approach 2 (recursion + memoization)
int minScoreTriangulation2(vector<int> &values){
    int n = values.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solveMem(values,0,n-1,dp);
}

// approach 3 (tabular / bottom-up approach)
int minScoreTriangulation3(vector<int> &v){
    int n = v.size();

    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=n-1;i>=0;i--){
        for(int j= i+2;j<n;j++){
            int ans = INT_MAX;
            for(int k=i+1;k<=j-1;k++){
                ans = min(ans,v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}



int main(){
    vector<int> values = {1,3,1,4,1,5};

    cout<<"apporoach 1 : pure recursion : "<<minScoreTriangulation(values)<<endl;
    cout<<"apporoach 2 : recursion + memoization : "<<minScoreTriangulation2(values)<<endl;
    cout<<"apporoach 3 : tabular : "<<minScoreTriangulation3(values)<<endl;
}