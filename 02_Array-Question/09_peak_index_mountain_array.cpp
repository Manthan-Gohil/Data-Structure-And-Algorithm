#include<bits/stdc++.h>
using namespace std;

int peak_index_mountain_array(vector<int> &nums){
    int n = nums.size();

    // mountain is having one peak in which left part of that index is less and right part of index is less
    int st = 1;
    int end = n - 2;

    while(st <= end){
        int mid = st + (end-st)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return nums[mid];

        else if(nums[mid] > nums[mid-1]){
            // move to right part
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
}

int main(){
    vector<int> nums = {0,3,8,9,5,2};
    cout<<peak_index_mountain_array(nums);
}