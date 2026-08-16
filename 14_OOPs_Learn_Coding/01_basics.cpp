// OOPs -> object oriented programming is the programming approach that are based on the classes and objects, which can contain data and code that manipulate that data.
// multiple objects can be created from one class


// class -> class is a user-defined datatype or blueprint that wrap the data and functions into a single entity (data members + member functions). classes do not have occupy memory, only objects occupy memory  

// objects -> object is the instance of a class that shows the real world entity.

// four pillers of OOPs
// 1. Encapsulation
// 2. Abstraction
// 3. Polymorphism
// 4. Inheritance

#include<bits/stdc++.h>
using namespace std;

class Person{
    // by default all data member and member function are private (if we explicitly do not give public access specifiers)
    int age;
    string name;
    string address;

    public:
    void input(){
        cout<<"Enter age"<<endl;
        cin>>age;

        cout<<"Enter name"<<endl;
        cin>>name;

        cout<<"Enter address"<<endl;
        cin>>address;
    }
    void output(){
        cout<<"Age : "<<age<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Address : "<<address<<endl;
    }
};

int main(){
    Person obj1,obj2,obj3;

    obj1.input();
    obj1.output();

    obj2.input();
    obj2.output();
   
    obj3.input();
    obj3.output();


}