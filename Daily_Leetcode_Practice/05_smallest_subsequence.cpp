// leetcode no 1081. Smallest Subsequence of Distinct Characters
// A subsequence is formed by deleting zero or more characters from a string without changing the order of the remaining characters.

#include<bits/stdc++.h>
using namespace std;

string smallestSubsequence(string &s){
    unordered_map<char,int> freq;
    unordered_map<char,bool> visited;

    for(char ch : s){
        freq[ch]++;
    }

    string st;

    for(char ch : s){
        freq[ch]--;

        if(visited[ch]){
            continue;
        }

        while(!st.empty() && st.back() > ch && freq[st.back()] > 0){
            visited[st.back()] = false;
            st.pop_back();
        }
        st.push_back(ch);
        visited[ch] = true;
    }
    return st;
}

int main(){
    string s = "bcabc";

    cout<<"Smallest subsequence of string = "<<smallestSubsequence(s)<<endl;
}