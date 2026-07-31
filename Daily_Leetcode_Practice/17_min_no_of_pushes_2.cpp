// leetcode no - 3016
#include<bits/stdc++.h>
using namespace std;

int minimumPushes(string word){
    vector<int> freq(26,0);

    for(char c : word){
        freq[c-'a']++;
    }

    sort(freq.rbegin(),freq.rend());

    int ans = 0;
    for(int i=0;i<26;i++){
        ans += freq[i] * (i/8 + 1);
    }
    return ans;
}

int minimumPushes2(string word){
    vector<int> freq(26,0);

    for(char c : word){
        freq[c-'a']++;
    }

    priority_queue<int> pq;

    for(int x : freq){
        if(x > 0){
            pq.push(x);
        }
    }

    int ans = 0;
    int position = 0;

    while(!pq.empty()){
        int f = pq.top();
        pq.pop();

        ans += f * (position/8 + 1);
        position++;
    }
    return ans;
}

int main(){
    string word = "xyzxyzxyzxyz";
    cout<<"minimum no of pushes to type word 2 = "<<minimumPushes(word)<<endl;
    cout<<"minimum no of pushes to type word 2 = "<<minimumPushes2(word)<<endl;
}