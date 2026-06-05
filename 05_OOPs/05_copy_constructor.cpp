// copy constructor ->
// special constructor (default) used to copy properties of one object into another

#include<bits/stdc++.h>
using namespace std;

class Teacher{
private:
    float salary;
public:
    string name;
    string dept;
    string subject;
    
    // parametrized constructor
    Teacher(string name, string dept, string subject, float salary){
        this->name = name; // left vala obj ki prop and right vala constructor ka parameter
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // copy constructor
    Teacher(Teacher &orgObj){
        cout<<"I am custom copy constructor"<<endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }

    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"subject : "<<subject<<endl;
    }
};

int main(){

    Teacher t1("Manthan","CSE","C++",250000);
    // t1.getInfo();

    Teacher t2(t1); // custom copy constructor
    t2.getInfo();
    return 0;
}