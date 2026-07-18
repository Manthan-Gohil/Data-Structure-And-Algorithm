// leetcode no - 1979
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int finGCD(vector<int> &nums){
    int n = nums.size();
    int minNum = INT_MAX;
    int maxNum = INT_MIN;

    for(int i=0;i<n;i++){
        minNum = min(minNum, nums[i]);
        maxNum = max(maxNum, nums[i]);
    }
    return gcd(minNum,maxNum);
}

int main(){
    vector<int> nums = {2,5,6,9,10};
    cout<<"GCD of smallest and largest number = "<<finGCD(nums)<<endl;

}