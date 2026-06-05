// for calling parametrized constructor of the parent class to child class

#include<bits/stdc++.h>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    
};

class Student : public Person{
public:
    int rollNo;
    // pass parametrized constructor in child constructor
    Student(string name, int age, int rollNo): Person(name, age){
        this->rollNo = rollNo;
    }

    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"roll no : "<<rollNo<<endl;
    }

};

int main(){
    Student s1("Manthan", 22, 230614);
    s1.getInfo();

}
