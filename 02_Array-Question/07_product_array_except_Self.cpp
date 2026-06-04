#include<bits/stdc++.h>
using namespace std;

// brute force approach
vector<int> product_Array_Except_Self(vector<int> &nums){
    int n = nums.size();
    int product = 1;
    for(int i=0;i<n;i++){
        product *= nums[i];
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        ans.push_back(product/nums[i]);
    }
    return ans;
}

// without using division operation
vector<int> product_Array_Except_Self2(vector<int> &nums){
    vector<int> ans;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int product = 1;
        for(int j=0;j<n;j++){
            if(i!=j){
                product *= nums[j];
            }
        }
        ans.push_back(product);
    }
    return ans;
}

// optimized O(n) TC but SC O(n) approach
vector<int> product_Array_Except_Self3(vector<int> &nums){
    int n = nums.size();
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);
    prefix[0] = 1;
    suffix[n-1] = 1;

    // prefix calculation
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]*nums[i-1];
    }
    // suffix calculation
    for(int j=n-2;j>=0;j--){
        suffix[j] = suffix[j+1]*nums[j+1];
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        ans.push_back(prefix[i]*suffix[i]);
    }
    return ans;
}

vector<int> product_Array_Except_Self4(vector<int> &nums){
    int n = nums.size();

    vector<int> ans(n,1);
    // prefix => ans
    for(int i=1;i<n;i++){
        ans[i] = ans[i-1]*nums[i-1];
    }
    // suffix
    int suffix = 1;
    for(int i=n-2;i>=0;i--){
        suffix *= nums[i+1]; //  ith suffix
        ans[i] *= suffix;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4};

    // vector<int> result = product_Array_Except_Self(nums);
    // vector<int> result = product_Array_Except_Self2(nums);
    // vector<int> result = product_Array_Except_Self3(nums);
    vector<int> result = product_Array_Except_Self4(nums);

    for(int value : result){
        cout<<value<<" ";
    }
}