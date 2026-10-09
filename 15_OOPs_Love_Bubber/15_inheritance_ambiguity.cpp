// ambiguity occurs in mainly multiple inheritance when two base classes have function with same name and if we create object of derived class then there is an ambiguity that which function the object will take while calling obj.func()

// this ambiguity will be resolved using scope resolution operator

#include<bits/stdc++.h>
using namespace std;

class A {
    public:
    void func(){
        cout<<"I am A"<<endl;
    }
};

class B {
    public:
    void func(){
        cout<<"I am B"<<endl;
    }
};

class C : public A, public B {

};

int main(){
    C obj;

    // obj.func(); // error, ambiguity arises

    // ambiguity resolved using scope resolution operator (::)
    obj.A :: func();
    obj.B :: func();

}