// hybrid inheritance 
// Hybrid inheritance combines two or more types of inheritance in the same class hierarchy

#include<bits/stdc++.h>
using namespace std;

class A {
    public:
    int age;

    void fun1(){
        cout<<"function 1"<<endl;
    }
};

class B : public A {
    public:
    void fun2(){
        cout<<"function 2"<<endl;
    }
};

class D {
    public:
    void fun3(){
        cout<<"function 3"<<endl;
    }
};

class C : public A, public D {
    public:
    void fun4(){
        cout<<"function 4"<<endl;
    }
};

int main(){
    C obj1;
    obj1.fun1();
    obj1.fun3();
    obj1.fun4();

}