// global class -> a class which is declared outside of all the functions or blocks
#include<bits/stdc++.h>
using namespace std;

class A{
    protected:
    int a;
    int b;

    public:
    void input(){
        cout<<"Enter a and b : "<<endl;
        cin>>a>>b;
    }
    void print(){
        cout<<"a = "<<a<<" b = "<<b<<endl;
    }
};
class B : public A {
  public:
  void display(){
    cout<<"a = "<<a<<" b = "<<b<<endl;
  }  
};
int main(){

    A obj1;
    B obj2;

    // obj1.input();
    // obj1.print();

    // obj2.display(); // a and b having garbage value because obj2 and obj1 having differnt memory location

    obj2.input();
    obj2.print();
    obj2.display(); // a and b having same value because it is created from same object

}