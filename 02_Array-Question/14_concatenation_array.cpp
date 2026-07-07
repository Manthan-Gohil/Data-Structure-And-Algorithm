#include<bits/stdc++.h>
using namespace std;

vector<int> concatenation_array(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(2*n);
    for(int i=0;i<2*n;i++){
        int k = i%n;
        ans[i] = nums[k];
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,1};
    vector<int> ans = concatenation_array(nums);
    for(int num : ans){
        cout<<num<<" ";
    }
}