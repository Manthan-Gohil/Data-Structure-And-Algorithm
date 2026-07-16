// leetcode no - 3867
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int gcdSum(vector<int> &nums){
    int n = nums.size();
    vector<int> prefixGcd(n);
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        mx = max(mx,nums[i]);
        prefixGcd[i] = gcd(mx,nums[i]);
    }
    sort(prefixGcd.begin(),prefixGcd.end());
    int i=0;
    int j = n-1;
    int sum = 0;
    while(i<j){
        sum += gcd(prefixGcd[i],prefixGcd[j]);
        i++;
        j--;
    }
    return sum;
}

int main(){
    vector<int> nums = {3,6,2,8};
    cout<<"Sum of gcd : "<<gcdSum(nums);
}