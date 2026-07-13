#include<bits/stdc++.h>
using namespace std;

// approach 1 pure recursion
int solve(vector<int> &days, vector<int> &costs, int index, int n){
    // base case
    if(index >= n) return 0;

    // 1 day pass
    int option1 = costs[0] + solve(days,costs,index+1,n);

    int i;
    // 7 day pass
    for(i=index;i<n && days[i] < days[index] + 7;i++);

    int option2 = costs[1] + solve(days,costs,i,n);
    // 30 day pass
    for(i=index;i<n && days[i] < days[index] + 30;i++);

    int option3 = costs[2] + solve(days,costs,i,n);

    return min(option1, min(option2,option3));
}

int minCostTickets(vector<int> &days, vector<int> &costs){
    int n = days.size();

    return solve(days,costs,0,n);
}

// approach 2 recursion + memoization
int solveMem(vector<int> &days, vector<int> &costs, int index, int n,vector<int> &dp){
    // base case
    if(index >= n) return 0;

    if(dp[index] != -1) return dp[index];
    // 1 day pass
    int option1 = costs[0] + solveMem(days,costs,index+1,n,dp);

    int i;
    // 7 day pass
    for(i=index;i<n && days[i] < days[index] + 7;i++);

    int option2 = costs[1] + solveMem(days,costs,i,n,dp);
    // 30 day pass
    for(i=index;i<n && days[i] < days[index] + 30;i++);

    int option3 = costs[2] + solveMem(days,costs,i,n,dp);

    dp[index] =  min(option1, min(option2,option3));
    return dp[index];
}

int minCostTickets2(vector<int> &days, vector<int> &costs){
    int n = days.size();
    vector<int> dp(n+1,-1);
    return solveMem(days,costs,0,n,dp);
}

// approach 3 tabulation

int minCostTickets3(vector<int> &days, vector<int> &costs){
    int n = days.size();
    vector<int> dp(n+1,INT_MAX);

    dp[n] = 0;

    for(int k=n-1;k>=0;k--){
    // 1 day pass
    int option1 = costs[0] + dp[k+1];

    int i;
    // 7 day pass
    for(i=k;i<n && days[i] < days[k] + 7;i++);

    int option2 = costs[1] + dp[i];
    // 30 day pass
    for(i=k;i<n && days[i] < days[k] + 30;i++);

    int option3 = costs[2] + dp[i];

    dp[k] =  min(option1, min(option2,option3));
    }
    return dp[0];
}

// approach 4 space optimized (using queue)

int minCostTickets4(vector<int> days, vector<int> costs){
    int ans = 0;

    queue<pair<int,int>> month;
    queue<pair<int,int>> week;

    for(int day:days){
        // step 1 remove expired days
        while(!month.empty() && month.front().first + 30 <= day)
            month.pop();
        while(!week.empty() && week.front().first + 7 <= day)
            week.pop();

        // step 2 add cost for current day
        week.push(make_pair(day, ans+costs[1]));
        month.push(make_pair(day, ans+costs[2]));

        // step 3 ans update
        ans = min(ans+costs[0], min(week.front().second, month.front().second));
    }
    return ans;
}

int main(){
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};

    cout<<"minimum cost for ticket (pure recursion) "<<minCostTickets(days,costs)<<endl; 
    cout<<"minimum cost for ticket (recursion + memoization) "<<minCostTickets2(days,costs)<<endl; 
    cout<<"minimum cost for ticket (tabulation) "<<minCostTickets3(days,costs)<<endl; 
    cout<<"minimum cost for ticket (space optimized) "<<minCostTickets4(days,costs)<<endl; 

}