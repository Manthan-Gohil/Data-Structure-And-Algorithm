#include<bits/stdc++.h>
using namespace std;

vector<int> next_greater_element_2(vector<int> &nums){
    int n = nums.size();
    stack<int> s;
    vector<int> ans(n,0);
    for(int i=2*n-1; i>=0;i--){

        while(s.size() > 0 && nums[s.top()] <= nums[i%n]){
            s.pop();
        }
        if(s.empty()){
            ans[i%n] = -1;
        }else{
            ans[i%n] = nums[s.top()];
        }
        s.push(i%n); // valid index
    }
    return ans;
}

int main(){
    vector<int> nums = {3,6,5,4,2};
    vector<int> ans = next_greater_element_2(nums);

    for(int num : ans){
        cout<<num<<" ";
    }

}