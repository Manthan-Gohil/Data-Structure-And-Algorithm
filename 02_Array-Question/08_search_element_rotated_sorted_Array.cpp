#include<bits/stdc++.h>
using namespace std;

int search_in_rotated_sorted_array(vector<int> &nums, int tar){

    int n = nums.size();

    int st = 0;
    int end = n - 1;

    while(st<=end){
        int mid = st + (end-st)/2;
        if(nums[mid] == tar) return mid;

        // left part is sorted
        if(nums[st]<=nums[mid]){
            if(nums[st] <= tar && tar <= nums[mid]){
                // left part is having the target value
                end = mid -1;
            }else{
                st = mid+1;
            }
        }
        // right part is sorted
        else{
            if(nums[mid] <= tar &&  tar<= nums[end]){
                // right part is having the target value
                st = mid + 1;
            }else{
                end = mid - 1;
            }

        }
    }
}

int main(){
    vector<int> nums = {6,7,0,1,2,3,4,5};

    cout<<"Target  value 0 present in index = "<<search_in_rotated_sorted_array(nums,0);
}