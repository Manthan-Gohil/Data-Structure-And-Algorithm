// multilevel inheritance
// When a class inherits from another derived class, forming a chain of inheritance, it is called multilevel inheritance

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

class GermanShephard : public Dog {

};

int main(){
    GermanShephard g;

    g.speak();

    cout<<g.age<<endl;
}