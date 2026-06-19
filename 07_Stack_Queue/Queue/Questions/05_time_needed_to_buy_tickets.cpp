#include<bits/stdc++.h>
using namespace std;

// approach 1 (using queue)
//T.C : O(n*m) -> Loop runs until queue is empty and in worst case all people have maximum m tickets 
//S.C : O(n)
 int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> que;

        for (int i = 0; i < n; i++) {
            que.push(i);
        }

        int time = 0;

        while (!que.empty()) {
            time++;
            int front = que.front();
            que.pop();
            
            tickets[front]--;
            
            if (k == front && tickets[front] == 0) {
                return time;
            }
            if (tickets[front] != 0) {
                que.push(front);
            }
        }

        return time;
}

// approach 2. (using simple logic)
//T.C : O(n)
//S.C : O(1)

int timeRequiredToBuy2(vector<int> &tickets, int k){
    int time = 0;
    int n = tickets.size();

    for(int i=0;i<n;i++){
        if(i <= k){
            time += min(tickets[i], tickets[k]);
        }
        else{
            time += min(tickets[k]-1, tickets[i]);
        }
    }
    return time;
}

int main(){
    vector<int> tickets = {2,3,2};
    int k = 2;

    cout<<"time to buy : "<<timeRequiredToBuy2(tickets,k)<<endl;

}