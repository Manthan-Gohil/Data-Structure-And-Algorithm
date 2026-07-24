// leetcode no - 3514
#include<bits/stdc++.h>
using namespace std;

int uniqueXorTriplets(vector<int> &nums){
    int n = nums.size();

    unordered_set<int> pairXor;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            pairXor.insert(nums[i]^nums[j]);
        }
    }

    unordered_set<int> tripletXor;

    for(int x : pairXor){
        for(int num : nums){
            tripletXor.insert(x ^ num);
        }
    }
    return tripletXor.size();
}

int main(){

    vector<int> nums = {6,7,8,9};
    cout<<"unique xor triptlet = "<<uniqueXorTriplets(nums)<<endl;

}