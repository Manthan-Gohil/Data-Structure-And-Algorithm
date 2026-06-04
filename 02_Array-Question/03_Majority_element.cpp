#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums){
    int n = nums.size();
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[nums[i]]++ ;

        // check if it becomes majority
        if(freq[nums[i]] > n/2){
            return nums[i];
        }
    }
    return -1;
    
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};

    int result = majorityElement(nums);
    cout<<result<<" ";
}