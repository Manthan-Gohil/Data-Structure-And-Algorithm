//local class -> a class which is declared inside a function or block is called local class
#include<bits/stdc++.h>
using namespace std;

void fun(){
    class A{
        int a;
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
