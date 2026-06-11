// calculate in reverse order
#include<bits/stdc++.h>
using namespace std;

vector<int> next_greater_element(vector<int> &nums){
    int n = nums.size();
    stack<int> s;
    vector<int> ans(n,0);
    for(int i=n-1;i>=0;i--){
        while(s.size() > 0 && s.top() <= nums[i]){ // removing invalid elements from stack
            s.pop();
        }
        if(s.empty()) {
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(nums[i]);
    }
    return ans;
}

int main(){
    vector<int> nums = {6,8,0,1,3};
    vector<int> ans = next_greater_element(nums);
    for(int num : ans){
        cout<<num<<" ";
    }
}