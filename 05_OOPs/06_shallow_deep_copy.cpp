// shallow & deep copy
// a shallow copy of an object copies all the member values from one object to another.
// a deep copy, on the other hand, not only copies the member values but also makes copies of an dynamically allocated memory that the members point to.

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

    Student(Student &obj){
        this->name = obj.name;
        this->cgpaPtr = obj.cgpaPtr;
    }
    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"cgpa : "<<*cgpaPtr<<endl;
    }
};

int main(){
    Student s1("Manthan", 8.9);
    s1.getInfo();

    Student s2(s1);
    *(s2.cgpaPtr) = 9.2;
    s1.getInfo(); // shallow copy problem -> we are changing cgpa of s2 but it will reflect in s1 also
    // that's why due to shallow copy problem, we use deep copy concept which also creates a copy of the dynamic allocated memory that the member points to  
    return 0;
}