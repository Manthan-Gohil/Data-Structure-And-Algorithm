#include<bits/stdc++.h>
using namespace std;
// TC O(n) SC O(n)
int uniqueIndex(string &str){
    // two data structures are used
    unordered_map<char, int> m;
    queue<int> q;

    for(int i=0;i<str.size();i++){
        // check character in map , if not then push its index in queue and increase count
        if(m.find(str[i]) == m.end()){
            q.push(i);
        }
        m[str[i]]++;

        while(q.size() > 0 && m[str[q.front()]] > 1){
            q.pop();
        }
    }
    return q.empty() ? -1 : q.front();
}

int main(){
    string str = "level";
    cout<<uniqueIndex(str);

}