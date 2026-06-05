// destructor -> opposite of constructor
// it is used to de-allocate the memory of object (only deallocate static allocated memory)
// for deleting dynamic allocated memory we use delelte keyword
// special function which created automatically by compiler
// ~className(){}

#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    double* cgpaPtr;

    Student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double; // dynamic memory allocation
        *cgpaPtr = cgpa;
    }
    // destructor
    ~Student(){
        cout<<"hi i delete everything"<<endl;
        delete cgpaPtr; // used only because of dynamic allocated memory
    }

    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"cgpa : "<<*cgpaPtr<<endl;
    }
};

int main(){
    Student s1("Manthan", 8.9);
    s1.getInfo();
    return 0;
}