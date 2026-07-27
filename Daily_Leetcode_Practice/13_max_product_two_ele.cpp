// leetcode no - 1464
#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> nums){
    sort(nums.begin(),nums.end());

    int n = nums.size();

    return (nums[n-1]-1)*(nums[n-2]-1);
}

int maxProduct2(vector<int> nums){
    int n = nums.size();

    int largest = -1;
    int secondLargest = -1;

    for(int i=0;i<n;i++){
        if(nums[i] > largest){
            secondLargest = largest;
            largest = nums[i];
        }
        else if(nums[i] > secondLargest){
            secondLargest = nums[i];
        }
    }
    return (largest-1)*(secondLargest-1);
}

int main(){
    vector<int> nums = {1,2,6,4,9};
    cout<<"max product of two different numbers minus 1 in both = "<<maxProduct(nums)<<endl;
    cout<<"max product of two different numbers minus 1 in both = "<<maxProduct2(nums)<<endl;
}