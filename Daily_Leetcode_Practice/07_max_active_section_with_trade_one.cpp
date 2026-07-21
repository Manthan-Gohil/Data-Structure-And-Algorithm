// leetcode no - 3499
#include<bits/stdc++.h>
using namespace std;

int maxActiveSectionsAfterTrade(string s){
    int n = s.length();

    int totalOnes = 0;
    int prevZeros = INT_MIN;
    int maxMerge = 0;

    int i=0;
    while(i<n){
        int j = i;
        while(j<n && s[i] == s[j]){
            j++;    
        }
        int len = j-i;
        if(s[i] == '1'){
            totalOnes += len;
        }else{
            maxMerge = max(maxMerge, prevZeros+len);
            prevZeros = len;
        }
        i = j;
    }
    return totalOnes + maxMerge;
}

int main(){
    string s = "01";
    cout<<"the maximum number of active sections in s after making the optimal trade = "<<maxActiveSectionsAfterTrade(s);

}