#include<bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int> &nums){
    int n = nums.size();
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());

    int left = (n-1)/2;
    int right = n-1;
    
    for(int i=0;i<n;i++){
        if(i%2 == 0){
            nums[i] = temp[left];
            left--;
        }else{
            nums[i] = temp[right];
            right--;
        }
    }
    
}

int main(){
    vector<int> nums = {1,5,1,1,6,4};

    wiggleSort(nums);

    for(int num : nums){
        cout<<num<<" ";
    }
}