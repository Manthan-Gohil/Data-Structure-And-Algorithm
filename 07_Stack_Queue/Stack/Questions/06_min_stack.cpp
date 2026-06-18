#include<bits/stdc++.h>
using namespace std;

class MinStack {
    public:
    stack<pair<int,int>> s;
    MinStack(){

    }

    void push(int val){
        if(s.empty()){
            s.push({val, val});
        }else{
            int minValue = min(val, s.top().second);
            s.push({val, minValue});
        }
    }

    void pop(){
        s.pop();
    }

    int top(){
        return s.top().first;

    } 

    int getMin(){
        return s.top().second;
    }
};

int main(){
    MinStack obj;
    
    obj.push(5);
    cout << obj.getMin() << endl;   // 5

    obj.push(3);
    cout << obj.getMin() << endl;   // 3

    obj.push(7);
    cout << obj.getMin() << endl;   // 3

    cout << obj.top() << endl;      // 7

    obj.pop();
    cout << obj.top() << endl;      // 3
    cout << obj.getMin() << endl;   // 3

    obj.pop();
    cout << obj.getMin() << endl;   // 5

}