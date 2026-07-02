#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &nums, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left < n && nums[largest] < nums[left]){
        largest = left;
    }
    if(right < n && nums[largest] < nums[right]){
        largest = right;
    }
    if(largest != i){
        swap(nums[largest], nums[i]);
        heapify(nums, n,largest);
    }
}

vector<int> merge_two_heaps(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();

    vector<int> ans;
    for(int i:a){
        ans.push_back(i);
    }
    for(int i:b){
        ans.push_back(i);
    }
    int size = ans.size();
    for(int i=size/2;i>=0;i--){
        heapify(ans,size,i);
    }
    return ans;
}

int main(){

}