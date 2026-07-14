#include<bits/stdc++.h>
using namespace std;

// dp[i][j] = number of ways to triangulate polygon formed by vertices i...j

// approach 1
int countPolygons(int i, int j){
    // base case
    if(i+1 == j) return 1;
    
    int ways = 0;
    for(int k=i+1;k<=j-1;k++){
        ways += countPolygons(i,k)*countPolygons(k,j);
    }
    return ways;
}

int solveMem(int i, int j, vector<vector<int>> &dp){
    // base case
    if(i+1 == j) return 1;
    
    if(dp[i][j] != -1) return dp[i][j];
    int ways = 0;
    for(int k=i+1;k<=j-1;k++){
        ways += solveMem(i,k,dp)*solveMem(k,j,dp);
    }
    dp[i][j] = ways;
    return dp[i][j];
}
int countPolygons2(int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solveMem(0,n-1,dp);
}

int countPolygons3(int n){
    vector<vector<int>> dp(n,vector<int>(n,0));

     for(int i=0;i<n-1;i++)
        dp[i][i+1]=1;

    for(int i=n-1;i>=0;i--){

        for(int j=i+2;j<n;j++){

            int ways=0;

            for(int k=i+1;k<=j-1;k++){

                ways += dp[i][k] * dp[k][j];

            }

            dp[i][j]=ways;
        }
    }

    return dp[0][n-1];
}

int main(){
    int n = 5;

    cout<<"Counting polygons (pure recursion) : "<<countPolygons(0,n)<<endl;
    cout<<"Counting polygons (top-down) : "<<countPolygons2(6)<<endl;
    cout<<"Counting polygons (bottom-up) : "<<countPolygons3(6)<<endl;
}