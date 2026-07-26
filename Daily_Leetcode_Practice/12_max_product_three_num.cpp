#include<bits/stdc++.h>
using namespace std;

// brute force approach TC O(nlogn)

int maxProduct(vector<int> &nums){
    int n = nums.size();

    sort(nums.begin(), nums.end());

    return max(nums[n-1]*nums[n-2]*nums[n-3], nums[n-1]*nums[0]*nums[1]);
}

int maxProduct1(vector<int> &nums){
     int largest1 = INT_MIN;
        int largest2 = INT_MIN;
        int largest3 = INT_MIN;
        
        int smallest1 = INT_MAX; 
        int smallest2 = INT_MAX;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] >= largest1){
                largest3 = largest2;
                largest2 = largest1;
                largest1 = nums[i];
            }
            else if(nums[i] >= largest2){
                largest3 = largest2;
                largest2 = nums[i];
            }
            else if(nums[i] >= largest3){
                largest3 = nums[i];
            }
            if(nums[i] <= smallest1){
                smallest2 = smallest1;
                smallest1 = nums[i];
            }
            else if(nums[i] <= smallest2){
                smallest2 = nums[i];
            }
        } 
        return max(largest1*largest2*largest3, largest1*smallest1*smallest2);
    
}

int main(){
    vector<int> nums = {1,2,3,-3,-7,4};

    cout<<"max product of three numbers = "<<maxProduct(nums)<<endl;
    cout<<"max product of three numbers = "<<maxProduct1(nums)<<endl;
}