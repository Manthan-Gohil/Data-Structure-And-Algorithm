#include<bits/stdc++.h>
using namespace std;

vector<int> previous_smaller_element(vector<int> &nums){
    stack<int> s;
    vector<int> ans(nums.size(),0);

    for(int i=0;i<nums.size();i++){
        while(s.size() > 0 && s.top() >= nums[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }
        s.push(nums[i]);
    }
    return ans;
}

int main(){
    vector<int> nums = {3,1,0,8,6};
    
    vector<int> ans = previous_smaller_element(nums);
    for(int num : ans){
        cout<<num<<" ";
    }
}