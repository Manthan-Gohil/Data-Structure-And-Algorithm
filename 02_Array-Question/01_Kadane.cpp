// maximum subarray sum
#include<bits/stdc++.h>
using namespace std;

//brute force approach
int maxSubarraySum(vector<int> &nums){
    int n = nums.size();
    int maxSum = INT_MIN;
    for(int st=0;st<n;st++){
        int currentSum = 0;
        for(int end=st;end<n;end++){
            currentSum += nums[end];
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}

// more optimized approach (Kadane algorithm)
int KadaneAlgo(vector<int> &nums){
    int n = nums.size();
    int currentSum = 0;
    int maxSum = INT_MIN;
    for(int i: nums){
        currentSum += i;
        maxSum = max(maxSum, currentSum);

        if(currentSum<0){
            currentSum = 0;
        }
    }
    return maxSum;

}

int main(){
    vector<int> arr = {1,2,3,4,5};
    // subarray traversal
    // int n = arr.size();
    // for(int st=0;st<n;st++){
    //     for(int end=st;end<n;end++){
    //         for(int i=st;i<=end;i++){
    //             cout<<arr[i]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }   
    vector<int> nums = {3,-4,5,4,-1,7,-8};
    // int result = maxSubarraySum(nums);
    int result2 = KadaneAlgo(nums);
    cout<<result2<<endl;
        
}