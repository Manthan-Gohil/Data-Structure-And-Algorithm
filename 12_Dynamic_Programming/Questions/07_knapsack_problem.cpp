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
    // if only 1 item to steal, then just compare its weight with the knapsack capacity
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

// approach 3 : tabulation method
int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity){
    // step 1:
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));

    // step 2: base case
    for(int i=weight[0];i<=capacity;i++){
        if(weight[0] <= capacity){
            dp[0][i] = value[0];
        }else{
            dp[0][i] = 0;
        }
    }

    // step 3 take care of remaining recursive calls
    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){

            int include = 0;
            if(weight[index] <= w){
                include = value[index] + dp[index-1][w-weight[index]];
            }
            int exclude = dp[index-1][w];
            dp[index][w] = max(include,exclude);
        }
    }
    return dp[n-1][capacity];
}



// approach 4 : (space optimized)
int knapsack4(vector<int> &weight, vector<int> &value, int n, int capacity){
    // step 1:
    vector<int> prev(capacity+1,0);
    vector<int> curr(capacity+1,0);

    // step 2: base case
    for(int i=weight[0];i<=capacity;i++){
        if(weight[0] <= capacity){
            prev[i] = value[0];
        }else{
            prev[i] = 0;
        }
    }

    // step 3 take care of remaining recursive calls
    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){

            int include = 0;
            if(weight[index] <= w){
                include = value[index] + prev[w-weight[index]];
            }
            int exclude = prev[w];
            curr[w] = max(include,exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}

// using only one vector 1D
int knapsack5(vector<int> &weight, vector<int> &value, int n, int capacity){
    // step 1:
    vector<int> curr(capacity+1,0);

    // step 2: base case
    for(int i=weight[0];i<=capacity;i++){
        if(weight[0] <= capacity){
            curr[i] = value[0];
        }else{
            curr[i] = 0;
        }
    }

    // step 3 take care of remaining recursive calls
    for(int index=1;index<n;index++){
        for(int w=capacity;w>=0;w--){

            int include = 0;
            if(weight[index] <= w){
                include = value[index] + curr[w-weight[index]];
            }
            int exclude = curr[w];
            curr[w] = max(include,exclude);
        }
    }
    return curr[capacity];
}

int main(){
    vector<int> weight = {1,3,4,5};
    vector<int> value = {1,4,5,7};

    cout<<"max profit in knapsack (pure recursion): "<<knapsack(weight,value,4,7)<<endl;
    cout<<"max profit in knapsack (recur + mem) : "<<knapsack2(weight,value,4,7)<<endl;
    cout<<"max profit in knapsack (tabulation) : "<<solveTab(weight,value,4,7)<<endl;
    cout<<"max profit in knapsack (space optimized) : "<<knapsack4(weight,value,4,7)<<endl;
    cout<<"max profit in knapsack (using only 1D vector) : "<<knapsack5(weight,value,4,7)<<endl;

}