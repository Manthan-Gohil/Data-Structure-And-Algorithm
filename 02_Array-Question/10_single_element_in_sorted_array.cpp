#include<bits/stdc++.h>
using namespace std;

int single_element_sorted_array(vector<int> &nums){
    int st = 0;
    int end = nums.size() - 1;

    while(st <= end){
        int mid = st + (end-st)/2;

        // edge or corner cases handling
        if(mid == 0 && nums[mid] != nums[mid+1] ) return mid;

        if(mid == nums.size()-1 && nums[mid] != nums[mid-2]) return mid;


        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
            return mid;
        }

        else if(mid % 2 == 0){ // true means both left & right part is having even numbers

            if(nums[mid] == nums[mid-1]){
                //value will be here therefore move to left side
                end = mid - 1;
            }else{
                // move to right side
                st = mid + 1;
            }
                    
        }else{ // true means both left and right side is having odd numbers
            if(nums[mid] == nums[mid-1]){
                // ans will be in right side
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    // vector<int> nums = {1,1,2,3,3,4,4,8,8};

    vector<int> nums = {3,3,7,7,10,11};

    cout<<"single number present at index = "<<single_element_sorted_array(nums);
}