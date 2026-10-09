// multiple inheritance
// When one derived class inherits from two or more base classes, it is called multiple inheritance

#include<bits/stdc++.h>
using namespace std;

class Animal {
    
    public:
    int age;
    int weight;

    void bark(){
        cout<<"barking"<<endl;
    }
};

class Human {

    public:
    string color;

    void speak(){
        cout<<"speaking"<<endl;
    }
};

// multiple inheritance 
class Hybrid : public Animal, public Human {

};

int main(){
    
    Hybrid h;
    h.speak();
    h.bark();
}