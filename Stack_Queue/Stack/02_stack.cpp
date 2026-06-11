// implementation stack using linked list
#include<bits/stdc++.h>
using namespace std;

class Stack{
    list<int> ll;
    public:
    void push(int val){ //0(1)
        ll.push_front(val);
    }

    int top(){  // O(1)
        return ll.front();
    }

    void pop(){  // O(1)
        ll.pop_front();
    }

    bool empty(){ // O(1)
        return ll.size() == 0;
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