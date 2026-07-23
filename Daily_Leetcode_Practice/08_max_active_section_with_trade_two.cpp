#include<bits/stdc++.h>
using namespace std;

vector<int> max_active_section(string s, vector<vector<int>> queries){
    int m = queries.size();

    vector<int> result;
    for(int row=0;row<m;row++){

            int left = queries[row][0];
            int right = queries[row][1];
           
            int totalOnes = 0;
            int prevZeros = INT_MIN;
            int maxMerge = 0;

            int i=left;
            
            while(i<=right){
                int j = i;
                while(j<=right && s[i] == s[j]){
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
        result.push_back(totalOnes + maxMerge);
        }
    
    return result;
}

int main(){

}