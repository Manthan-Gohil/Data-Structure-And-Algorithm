// implementation stack using arrays/vector
#include<bits/stdc++.h>
using namespace std;

class Stack{
    vector<int> v;
    public:
    void push(int val){ //0(1)
        v.push_back(val);
    }

    int top(){  // O(1)
        return v[v.size()-1];
    }

    void pop(){  // O(1)
        v.pop_back();
    }

    bool empty(){ // O(1)
        return v.size() == 0;
    }
};

int main(){

    Stack s; 
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}