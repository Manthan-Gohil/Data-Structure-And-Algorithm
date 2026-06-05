// inheritance
// when properties & member functions of base class are passed on to the derived class.

// code reusability
// whenever we create object of derived class in main function then firstly base class constructor called and then dervied class constructor called.
// destructor have opposite things firstly deallocate child obj then parent obj
#include<bits/stdc++.h>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(){
        cout<<"Parent constructor called"<<endl;
    }
    ~Person(){
        cout<<"Parent destructor called"<<endl;
    }
};

class Student : public Person{
public:
    int rollNo;

    Student(){
        cout<<"child constructor called"<<endl;
    }
    ~Student(){
        cout<<"child destructor called"<<endl;
    }

    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"roll no : "<<rollNo<<endl;
    }

};

int main(){
    Student s1;
    s1.name = "Manthan";
    s1.age = 22;
    s1.rollNo = 230614;

    s1.getInfo();

}
