// given a binary matrix , find out the maximum size square sub-matrix with all 1s
#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix, int i, int j, int &maxi){
    if(i >= matrix.size() || j >= matrix[0].size()){
        return 0;
    }

    int right = solve(matrix,i,j+1,maxi);
    int diagonal = solve(matrix,i+1,j+1,maxi);
    int bottom = solve(matrix,i+1,j,maxi);

    if(matrix[i][j] == 1){
        int ans = 1 + min(right,min(diagonal,bottom));
        maxi = max(maxi,ans);
        return ans;
    }else{
        return 0;
    }

}

int maxSquare(vector<vector<int>> &matrix){
    int maxi = 0;
    solve(matrix,0,0,maxi);
    return maxi;
}

int solveMem(vector<vector<int>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp){
    if(i >= matrix.size() || j >= matrix[0].size()){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int right = solveMem(matrix,i,j+1,maxi,dp);
    int diagonal = solveMem(matrix,i+1,j+1,maxi,dp);
    int bottom = solveMem(matrix,i+1,j,maxi,dp);

    if(matrix[i][j] == 1){
        dp[i][j] = 1 + min(right,min(diagonal,bottom));
        maxi = max(maxi,dp[i][j]);
        return dp[i][j];
    }else{
        return dp[i][j] = 0;
    }
}

int maxSquare2(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col,-1));
    int maxi = 0;
    solveMem(matrix,0,0,maxi,dp);
    return maxi;
}

int solveTab(vector<vector<int>> &matrix, int &maxi){
    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> dp(row+1,vector<int>(col+1,0));
    
    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){

            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int bottom = dp[i+1][j];

            if(matrix[i][j] == 1){
                dp[i][j] = 1 + min(right,min(diagonal,bottom));
                maxi = max(maxi,dp[i][j]);
            }else{
                dp[i][j] = 0;
            }   
        }
    }
    return dp[0][0];
}

int maxSquare3(vector<vector<int>> &matrix){
    int maxi = 0;
    solveTab(matrix,maxi);
    return maxi;
}

int solveSO(vector<vector<int>> &matrix, int &maxi){
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> curr(col+1,0);
    vector<int> next(col+1,0);
    
    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){

            int right = curr[j+1];
            int diagonal = next[j+1];
            int bottom = next[j];

            if(matrix[i][j] == 1){
                curr[j] = 1 + min(right,min(diagonal,bottom));
                maxi = max(maxi,curr[j]);
            }else{
                curr[j] = 0;
            }   
        }
        next = curr;
    }
    return next[0];
}

int maxSquare4(vector<vector<int>> &matrix){
    int maxi = 0;
    solveSO(matrix,maxi);
    return maxi;
}

int main(){
    vector<vector<int>> matrix = {{1,0,1,0,0},
                                  {1,0,1,1,1},
                                  {1,1,1,1,1},
                                  {1,0,0,1,0},};
    
    cout<<"Approach 1 : "<<maxSquare(matrix)<<endl;
    cout<<"Approach 2 (rec + mem) : "<<maxSquare2(matrix)<<endl;
    cout<<"Approach 3 (bottom-up) : "<<maxSquare3(matrix)<<endl;
    cout<<"Approach 3 (space optimized) : "<<maxSquare4(matrix)<<endl;
}