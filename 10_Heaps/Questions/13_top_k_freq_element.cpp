#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;

        for(auto it:freq){

            int number = it.first;
            int frequency = it.second;

            if(minHeap.size() < k){

                minHeap.push({frequency,number});
            }
            else{

                if(frequency > minHeap.top().first){

                    minHeap.pop();

                    minHeap.push({frequency,number});
                }
            }
        }

        vector<int> ans;

        while(!minHeap.empty()){

            ans.push_back(minHeap.top().second);

            minHeap.pop();
        }

        return ans;
    }
};