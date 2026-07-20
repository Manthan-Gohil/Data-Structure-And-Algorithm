#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &nums, int k){
    int m = nums.size();
    int n = nums[0].size();

    vector<int> arr;

    // convert 2d to 1d array
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr.push_back(nums[i][j]);
        }
    }

    int total = arr.size();
    k %= total;

    vector<int> shifted(total);

    for(int i=0;i<total;i++){
        int idx = (i+k)%total;
        shifted[idx] = arr[i];
    }

    // convert 1D to 2D array
    int index=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            nums[i][j] = shifted[index++];
        }
    }
    return nums;
}

int main(){
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    shiftGrid(nums,1);

    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[0].size();j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}