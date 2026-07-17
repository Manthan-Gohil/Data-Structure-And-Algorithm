// leetcode no - 3312
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
// brute force
vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        vector<int> gcdPairs;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                gcdPairs.push_back(gcd(nums[i], nums[j]));
            }
        }

        sort(gcdPairs.begin(), gcdPairs.end());

        vector<int> ans(queries.size());

        for(int i = 0; i < queries.size(); i++) {
            ans[i] = gcdPairs[queries[i]];
        }

        return ans;
    }
// optimized code
vector<int> gcdValues2(vector<int>& nums, vector<long long>& queries) {
        int MAX = *max_element(nums.begin(), nums.end());

        vector<int> freq(MAX + 1);

        for (int x : nums)
            freq[x]++;

        vector<long long> divisible(MAX + 1);

        for (int d = 1; d <= MAX; d++) {
            for (int multiple = d; multiple <= MAX; multiple += d) {
                divisible[d] += freq[multiple];
            }
        }

        vector<long long> exact(MAX + 1);

        for (int d = MAX; d >= 1; d--) {

            long long cnt = divisible[d];

            exact[d] = cnt * (cnt - 1) / 2;

            for (int multiple = 2 * d; multiple <= MAX; multiple += d) {
                exact[d] -= exact[multiple];
            }
        }

        vector<long long> prefix(MAX + 1);

        for (int i = 1; i <= MAX; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {

            int g = lower_bound(prefix.begin() + 1,
                                prefix.end(),
                                q + 1) - prefix.begin();

            ans.push_back(g);
        }

        return ans;
    }