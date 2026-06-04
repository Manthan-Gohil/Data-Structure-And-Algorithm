// return pair in sorted array with target sum(basically array is sorted given in the question)
#include<bits/stdc++.h>
using namespace std;

// brute force approach
vector<int> pairSum(vector<int> &nums, int target){
    int n = nums.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

// two pointer approach
vector<int> pairSum2(vector<int> &nums, int target){
    int n = nums.size();

    int i = 0;
    int j = nums.size() - 1;
    vector<int> ans;
    while(i<=j){
        if(nums[i]+nums[j] == target){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        };
        if(nums[i]+nums[j] > target) j--;
        if(nums[i]+nums[j] < target) i++; 
    }
    return ans;
}
int main(){

    vector<int> nums = {2,7,11,15};

    // vector<int> answer = pairSum(nums, 9);
    // for(int i : answer){
    //     cout<<i<<" ";
    // }
    vector<int> ans = pairSum2(nums,18);
    for(int i: ans){
        cout<<i<<" ";
    }
}