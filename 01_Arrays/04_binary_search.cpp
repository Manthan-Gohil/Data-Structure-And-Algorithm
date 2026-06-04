#include<bits/stdc++.h>
using namespace std;

// binary search
int binarySearch(vector<int> &nums, int target){
    int st = 0;
    int end = nums.size() - 1;

    while(st<=end){
        int mid = st + (end-st)/2;
        if(target < nums[mid]){
            end = mid-1;
        }
        else if(target > nums[mid]){
            st = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

// recursive approach
int binarySearch2(vector<int> &nums, int tar, int st, int end){

    if(st <= end){
        int mid = st + (end-st)/2;
        if(tar < nums[mid]){
           return binarySearch2(nums, tar, st, mid-1);
        }
        else if(tar > nums[mid]){
           return binarySearch2(nums, tar, mid+1,end);
        }
        else{
            return mid;
        }
    }
    return -1;
}


int main(){

    vector<int> nums = {-1,0,4,6,8,9};

    cout<<"number at index = "<<binarySearch(nums,6);
    cout<<endl;
    cout<<"number at index = "<<binarySearch2(nums,6, 0, nums.size()-1);
}