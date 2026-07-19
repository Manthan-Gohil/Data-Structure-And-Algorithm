// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.
#include<bits/stdc++.h>
using namespace std;

bool validAnagram(string s, string t){
    unordered_map<char,int> mp1;
    unordered_map<char,int> mp2;

    for(char ch : s){
        mp1[ch]++;
    }
    for(char ch : t){
        mp2[ch]++;
    }
    if(mp1 == mp2) return true;
    else return false;
}

bool validAnagram2(string s, string t){
    vector<int> freq(26,0);

    if(s.length() != t.length()) return false;

    for(int i=0;i<s.length();i++){
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for(int count : freq){
        if(count != 0) return false;
    }
    return true;
}

int main(){
    string s = "anagram";
    string t = "nagaram";

    cout<<"Valid anagram 1 = "<<validAnagram(s,t)<<endl;
    cout<<"Valid anagram 2 = "<<validAnagram2(s,t)<<endl;
}