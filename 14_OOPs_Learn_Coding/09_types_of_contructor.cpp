#include<bits/stdc++.h>
using namespace std;

class test{
    private:
    int a, b;
    public:
    test(){ // default constructor
        cout<<"Default constructor:"<<endl;
        cout<<"Enter a and b : "<<endl;
        cin>>a>>b;
        cout<<a<<" "<<b<<endl;
    }
    test(int x, int y){ // parametrized constructor
        cout<<"Parametrized constructor:"<<endl;
        a = x;
        b = y;
        cout<<a<<" "<<b<<endl;
    }
    test(test &obj){ // copy constructor
        cout<<"copy constructor:"<<endl;
        a = obj.a;
        b = obj.b;
        cout<<a<<" "<<b<<endl;
    }
};

int main(){
    test obj1;
    test obj2(10,20);
    test obj3 = obj1;
    test obj4 = obj2;
}