// span - max number of consequetive days from today, if price <= today's price
// prevhigh - immedeatre greater value
#include<bits/stdc++.h>
using namespace std;
// TC O(n) SCO(N)
vector<int> stockSpan(vector<int> &price){
    vector<int> ans(price.size(),0);
    stack<int> s;

    for(int i=0;i<price.size();i++){

        while(s.size() > 0 && price[s.top()] <= price[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = i+1;
        }else{
            ans[i] = i - s.top(); // i - prevHigh
        }
        s.push(i);
    }
    return ans;
}

int main(){
    vector<int> price = {100, 80, 60, 70, 60, 65, 85};

    vector<int> ans = stockSpan(price);
    for(int num : ans){
        cout<<num<<" ";
    }

}