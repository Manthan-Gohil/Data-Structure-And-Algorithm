// this is a special pointer in c++ that points to the current object.

// this->prop is same as *(this).prop

#include<bits/stdc++.h>
using namespace std;

class Teacher{
private:
    float salary;
public:
    string name;
    string dept;
    string subject;
    // non parametrized constructor
    Teacher(){
        dept = "CSE";
    }
    // parametrized constructor
    Teacher(string name, string dept, string subject, float salary){
        this->name = name; // left vala obj ki prop and right vala constructor ka parameter
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"subject : "<<subject<<endl;
    }
};

int main(){

    Teacher t2("Manthan","CSE","C++",250000);
    t2.getInfo();
    return 0;
}