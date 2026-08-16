// classes can be initialized into three types
// 1. local class
// 2. global class
// 3. nested class

//local class -> a class which is declared inside a function or block is called local class

// it is required to create an object of that local class inside a function
#include<bits/stdc++.h>
using namespace std;

void fun(){
    class A{

        int a; // (private by default)
        int b;
        public:
        void show(){
            cout<<"Enter two numbers :"<<endl;
            cin>>a>>b;
            cout<<"a = "<<a<<"b = "<<b<<endl;
        }
    };
    A obj;
    obj.show();
}

int main(){

    fun();

}
