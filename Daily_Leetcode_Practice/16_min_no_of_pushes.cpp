// leetcode no - 3014
#include<bits/stdc++.h>
using namespace std;


// method 1 TC O(n)
int minimumPushes(string word){
    int  ans = 0;

    int n = word.size();

    for(int i=0;i<n;i++){
        ans += ((i/8) + 1);
    }
    return ans;
}

// method 2 TC O(1)
int minimumPushes2(string word){
    int n = word.size();

    int ans = 0;

    int first = min(n,8);
    ans += first;
    n -= first;

    int second = min(n,8);
    ans += second*2;
    n -= second;

    int third = min(n,8);
    ans += third*3;
    n -= third;

    ans += n*4;

    return ans;

}

int main(){
    string word = "abcdefghi";
    cout<<"minimum number of pushes to type word 1 = "<<minimumPushes(word)<<endl;
    cout<<"minimum number of pushes to type word 1 = "<<minimumPushes2(word)<<endl;
}