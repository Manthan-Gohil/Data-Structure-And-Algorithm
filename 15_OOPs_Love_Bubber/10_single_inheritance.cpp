// single inheritance 
// When one derived class inherits from only one base class, it is called single inheritance.

#include<bits/stdc++.h>
using namespace std;

class Animal {
    
    public:
    int age;
    int weight;

    void speak(){
        cout<<"speaking"<<endl;
    }
};

class Dog : public Animal {

};

int main(){
    Dog d;
    d.speak();

    cout<<d.age<<endl;
}