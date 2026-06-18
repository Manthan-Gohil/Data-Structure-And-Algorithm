// implement queue operations using two stack
// approach -> one of the operation either push or pop, anyone operation will take O(n) TC
// i will take push operation for O(n)
// push operation approach
// 1. copy all the elements from s1 and paste to s2 and remove from s1
// 2. now push data to s1
// 3. now push data from s2 to s1 and remove those data from s2

#include<bits/stdc++.h>
using namespace std;

class MyQueue{
    stack<int> s1;
    stack<int> s2;
    
    public:

    void push(int data){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop(){
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int front(){
        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }
};

int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.pop();

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

}
