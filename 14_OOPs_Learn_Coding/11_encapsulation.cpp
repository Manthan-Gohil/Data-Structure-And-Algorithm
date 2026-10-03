// encapsulation -> it mean binding data and methods within a class, providing control over accessibility and it prevents external code from directly modifying the internal data of an object.

#include<bits/stdc++.h>
using namespace std;

class Encap{
    int a; // private member

    public:
    void show(int x){
        a = x;
        cout<<"a = "<<a<<endl;
    }
};

int main(){
    Encap e;
    // cout<<e.a; // error, private member can not accessible outside class 
    e.show(6);
}