// OOPs helps to solve the problem in real life scenarios

// classes & object
// objects are entities in the real world
// class is like blueprint of these entities
// class can be group of objects

// each object is having different data members and member functions
// OOPs provides code reusability (do not have to create multiple variables)

// accress modifiers
// private : data and methods accessible inside class
// public : data and methods accessible to everyone
// protected : data and methods accessible inside class and to its derived class
// by default if we are not declaring the access modifier then it will be private by default means data/methods can not accessible outside class
#include<bits/stdc++.h>
using namespace std;

class Teacher{
private:
    float salary;
public:
    string name;
    string dept;
    string subject;

    void changeDept(string newDept){
        dept = newDept;
    }

    // setter -> special function which used to set value of private variable
    void setSalary(float s){
        salary = s;
    }
    // getter -> special function which is used to get value of private variable
    float getSalary(){
        return salary;
    }
};

int main(){
    // creating an object t1
    Teacher t1;
    t1.name = "Manthan";
    t1.subject = "C++";
    t1.dept = "CSE";
    // t1.salary = 25000; // can not accessible
    cout<<t1.name<<endl;
    
    t1.setSalary(25000);
    cout<<t1.getSalary()<<endl;
    return 0;
}