#include<bits/stdc++.h>
using namespace std;

int stock_Buy_Sell(vector<int> &prices){
    int n = prices.size();

    int maxProfit = 0;
    int bestBuy = prices[0]; // always start with starting value

    for(int i=1;i<n;i++){
        if(prices[i] > bestBuy){
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
        // checking current price will become bestBuy price
        bestBuy = min(bestBuy, prices[i]); 
    }

    return maxProfit;

}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    int maxprofit = stock_Buy_Sell(prices);

    cout<<"maxprofit = "<<maxprofit<<endl;

}