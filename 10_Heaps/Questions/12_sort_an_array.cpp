#include<bits/stdc++.h>
using namespace std;

class Solution {
private:

    void heapify(vector<int> &nums,
                 int size,
                 int i){

        int largest = i;

        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size &&
           nums[largest] < nums[left]){
            largest = left;
        }

        if(right < size &&
           nums[largest] < nums[right]){
            largest = right;
        }

        if(largest != i){

            swap(nums[largest], nums[i]);

            heapify(nums,size,largest);
        }
    }

    void heapSort(vector<int> &nums,
                  int &n){

        int size = n;

        while(size > 1){

            swap(nums[size-1], nums[0]);

            size--;

            heapify(nums,size,0);
        }
    }

public:

    vector<int> sortArray(vector<int>& nums) {

        int size = nums.size();

        // Build Max Heap
        for(int i=size/2-1;i>=0;i--){

            heapify(nums,size,i);
        }

        // Heap Sort
        heapSort(nums,size);

        return nums;
    }
};