// leetcode no - 3513
#include<bits/stdc++.h>
using namespace std;

int uniqueXorTriplets(vector<int> &nums){
    int n = nums.size();

    if(n < 3) return n;

    int x = n;
    int bits = 0;

    while(x != 0){
        bits++;
        x >>= 1; // right shift 1 bit
    }

    return 1 << bits; // left shift to get 2^(no of bits);
}

int main(){

}