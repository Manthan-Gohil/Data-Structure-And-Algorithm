#include<bits/stdc++.h>
using namespace std;

int removeDuplicate(vector<int> &nums){
    if(nums.empty()) return 0;

    int write = 1;
    for(int i=1;i<nums.size();i++){
        if(nums[i] != nums[write-1]){
            nums[write] = nums[i];
            write++;
        }
    }
    return write;
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int ans = removeDuplicate(nums);
    cout<<"number of unique elements : "<<ans<<endl;
}