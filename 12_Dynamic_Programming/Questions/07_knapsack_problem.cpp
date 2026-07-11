#include<bits/stdc++.h>
using namespace std;

// approach 1 pure recursion
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight){
    // base case
    if(n == 0){
        if(weight[0] < maxWeight) return value[0];
        else return 0;
    }

    int include = 0;
    if(weight[n] <= maxWeight){
        include = value[n] + knapsack(weight, value, n-1, maxWeight - weight[n]);
    }
    int exclude = knapsack(weight, value, n-1, maxWeight);

    int ans = max(include,exclude);
    return ans;

}

// approach 2 recursion + memoization
int solveMem(vector<int> &weight, vector<int> &value, int n, int maxWeight, vector<vector<int>> &dp){
    // base case
    if(n == 0){
        if(weight[0] < maxWeight) return value[0];
        else return 0;
    }

    if(dp[n][maxWeight] != -1) return dp[n][maxWeight];

    int include = 0;
    if(weight[n] <= maxWeight){
        include = value[n] + solveMem(weight, value, n-1, maxWeight - weight[n],dp);
    }
    int exclude = solveMem(weight, value, n-1, maxWeight,dp);

    dp[n][maxWeight] = max(include,exclude);
    return dp[n][maxWeight];

}

int knapsack2(vector<int> weight, vector<int> value, int n, int  maxWeight){
    // two states are changing n and maxweight that why we create 2D array
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return solveMem(weight,value,n-1,maxWeight,dp);
}

int main(){
    vector<int> weight = {1,3,4,5};
    vector<int> value = {1,4,5,7};

    cout<<"max profit in knapsack (pure recursion): "<<knapsack(weight,value,4,7)<<endl;
    cout<<"max profit in knapsack (recur + mem) : "<<knapsack2(weight,value,4,7)<<endl;

}