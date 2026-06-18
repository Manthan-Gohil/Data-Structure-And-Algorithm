// implement stack operations using two queue
// approach -> one of the operation either push or pop, anyone operation will take O(n) TC
// i will take push operation for O(n)
// push operation approach
// 1. copy all the elements from q1 and paste to q2 and remove from q1
// 2. now push data to q1
// 3. now push data from q2 to q1 and remove those data from q2

#include<bits/stdc++.h>
using namespace std;

class MyStack{
    queue<int> q1;
    queue<int> q2;

    public:

    void push(int data){ // O(n)
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop(){ // O(1)
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top(){ // O(1)
        return q1.front();
    }

    bool empty(){ // O(1)
        return q1.empty(); // imp part
    }
};

int main(){
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"top element : "<<s.top()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}