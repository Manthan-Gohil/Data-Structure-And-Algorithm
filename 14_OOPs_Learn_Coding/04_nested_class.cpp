// nested class -> a class which is created or contain inside another class called nested class
#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    // int a,b; // class B can not access these variables and gives error because outside of class B
    class B{ // member variable of class A
        int a;
        int b;

        public:
        void input(){ // member function of class B
            cout<<"Enter the a and b "<<endl;
            cin>>a>>b;
        }
        void print(){
            cout<<"a = "<<a<<" b = "<<b<<endl;
        }
    };
};

int main(){
    // A :: B obj; // this is the object for class B using scope resolution operator.
    // obj.input();
    // obj.print();

    // B obj; (this is incorrect)
    // obj.input();
    // obj.print();
}