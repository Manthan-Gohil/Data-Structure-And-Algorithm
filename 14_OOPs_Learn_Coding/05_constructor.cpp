// constructor -> constructor is a special member function of class which is used to create or initialize the object

// feature of constructor ->
// 1. a constructor can only have one access modifier, which is public.
// 2. a constructor is never inherited or overridden
// 3. each and every c++ class has constructor either it is provided by compiler by default or explicitly created
// 4. constructor has same name as class name
#include<bits/stdc++.h>
using namespace std;

class A{
    int a;
    // constructor
    public:
    A(){
        a = 100;
    }
    void show(){
        cout<<"a = "<<a<<endl;
    }
};

int main(){
    A obj; // object is created in this syntax only when without explicity created constructor
    // A obj = A(); // using constructor to create object (we can not use this syntax to create object if we do not create constructor explicitly)
    obj.show();

}