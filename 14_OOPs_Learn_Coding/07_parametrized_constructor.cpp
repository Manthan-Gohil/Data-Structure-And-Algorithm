// parametrized constructor -> a constructor that accepts or receives parameters is called parametrized constructor.
#include<bits/stdc++.h>
using namespace std;

class A{
    int a,b;
    public:
    A(int x, int y){ // parametrized constructor
        a = x;
        b = y;
    }
    void show(){
        cout<<"a = "<<a<<" b = "<<b<<endl;
    }
};

int main(){
    A obj(10,20);
    // A obj = A(10,20); // can also be created by this syntax
    obj.show();
}