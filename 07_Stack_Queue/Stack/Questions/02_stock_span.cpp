// span - max number of consequetive days from today, if price <= today's price
// prevhigh - immedeatre greater value
#include<bits/stdc++.h>
using namespace std;
// TC O(n) SC O(N)
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

// leetcode solution
// class StockSpanner {
//     stack<pair<int,int>> s; // stores {currentPrice, span}
// public:
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
       
//         int span = 1;

//         while(!s.empty() && s.top().first <= price){
//             span += s.top().second;
//             s.pop();
//         }
//         s.push({price, span});
//         return span;
//     }
// };

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */