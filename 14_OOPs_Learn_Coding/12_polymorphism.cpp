// polymorphism -> it is a concept in which an object can be treated in different ways. It means that object of a class can be used as object of their derived class

// polymorphism is two types ->
// 1. static polymorphism (compile-time polymorphism) -> implemented through function overloading or operator overloading
// 2. dynamic polymorphism (run-time polymorphism) -> implemented through function overriding

#include<bits/stdc++.h>
using namespace std;

// compile-time polymorphism (function overloading)
class A{
    public:
    void add(int a, int b){
        cout<<"a + b = "<<a+b<<endl;
    }

    void add(int a, int b, int c){
        cout<<"a + b + c = "<<a+b+c<<endl;
    }
    void add(double a, double b){
        cout<<"Double a + b = "<<a+b<<endl;
    }
};

// run-time polymorphism
class Animal {
public:
    virtual void sound() {
        cout << "Animal makes sound" << endl;
    }
};
class Dog : public Animal {
public:

    void sound() {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() {
        cout << "Cat meows" << endl;
    }
};

int main(){
    // compile time
    A obj;
    obj.add(10,20);
    obj.add(10,20,30);
    obj.add(10.5,20.6);

    // run time
    Animal* animal; // The pointer is of type Animal*, but it can point to different child objects: animal = &dog; because of virtual keyword on base class function, if we remove the virtual keyword then it will point to animal type and call base class function
    Dog dog;
    animal = &dog;
    animal->sound();
    Cat cat;
    animal = &cat;
    animal->sound();
}
