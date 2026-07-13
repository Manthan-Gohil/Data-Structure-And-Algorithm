#include<bits/stdc++.h>
using namespace std;

// tabular method
int solve(vector<vector<int>> &mat, int &count){
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row+1,vector<int>(col+1,0));

    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int bottom = dp[i+1][j];


            if(mat[i][j] == 1){
                dp[i][j] = 1 + min(right,min(diagonal,bottom));
                count += dp[i][j];
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
}

// approach 2 : space optimized method
int solveSO(vector<vector<int>> &mat, int &count){
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row+1,vector<int>(col+1,0));
    vector<int> curr(col+1,0);
    vector<int> next(col+1,0);

    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){
            int right = curr[j+1];
            int diagonal = next[j+1];
            int bottom = next[j];


            if(mat[i][j] == 1){
                curr[j] = 1 + min(right,min(diagonal,bottom));
                count += curr[j];
            }else{
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return next[0];
}

int countSquares(vector<vector<int>> &matrix){
    int count = 0;
    solveSO(matrix, count);
    return count;
}

int main(){
    vector<vector<int>> matrix = {{1,0,1,0,0},
                                  {1,0,1,1,1},
                                  {1,1,1,1,1},
                                  {1,0,0,1,0},};
    cout<<"count square : (tabular) "<<countSquares(matrix)<<endl;

}