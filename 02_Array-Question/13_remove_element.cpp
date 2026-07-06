#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val){
    if(nums.empty()) return 0;
    int write = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i] != val){
            nums[write] = nums[i];
            write++;
        }
    }
    return write;
}

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    cout<<"Number of elements not equal to val : "<<removeElement(nums,2)<<endl;

}