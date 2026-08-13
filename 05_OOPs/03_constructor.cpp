// constructor ->
// it is a special method invoked automatically at the time of object creation. Used for Initialization.

// same name as class
// constructor does not have a return type
// only called once (automatically), at object creation
// memory allocation happens when constructor is called
// constructor is always created public

// constructor can be three types
// non parametrized constructor
// parametrized constructor
// copy constructor

// if multiple constructors of same name and its type different are in same class then it is called constructor overloading (example of polymorphism)


#include<bits/stdc++.h>
using namespace std;

class Teacher{
private:
    float salary;
public:
    // non parametrized constructor
    Teacher(){
        cout<<"Hi i am constructor"<<endl;
        dept = "CSE";
    }
    // parametrized constructor
    Teacher(string n, string d, string s, float sal){
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }
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

    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"subject : "<<subject<<endl;
    }
};

int main(){
    // creating an object t1
    Teacher t1;
    // cout<< t1.dept <<endl;

    Teacher t2("Manthan","CSE","C++",250000);

    t2.getInfo();
    return 0;
}