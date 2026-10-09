// inheritance
// it is the concept in which one class derive/inherit the properties and behaviour of another class.

// inheritance is used for code reusability.
// Runtime polymorphism (method overriding) can be achieved by inheritance only.

// Sub class -> the class which inherit the properties or behaviour of another class.
// Super class -> the class whose properties or behaviour is inherited is called super class or base class.


// mode of inheritance
// Base class member | public inheritance | protected inheritance | private inheritance 
// public            |  public            | protected             | private
// protected         |  protected         | protected             | private
// private           |  N/A               | N/A                   | N/A

// types of inheritance 
// five types of inheritance
// Single inheritance
// Multiple inheritance
// Multilevel inheritance
// Hierarchical inheritance
// Hybrid inheritance


#include<bits/stdc++.h>
using namespace std;

class Human {
    
    public:
    int height;
    int weight;
    int age;

    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }
};

class Male : public Human {

    public:
    string color;

    void sleep(){
        cout<<"Male sleeping"<<endl;
    }
};

int main(){

    Male object1;
    cout<<object1.age<<endl;
    cout<<object1.weight<<endl;
    cout<<object1.height<<endl;
    
    cout<<object1.color<<endl;

    object1.setWeight(63);
    cout<<object1.weight<<endl;
    object1.sleep();

    return 0;
}


