// encapsulation -> wrapping up data member and member function into a single unit called class.

// why encapsulation?
// to protect data members / data hiding
// if we want we can make class read only
// code reusability
// encapsulation is used as a unit testing

// fully encapulated class -> all data members are private (data members are used in same class only)

// but private data members are accessible using getter and setter function

#include<bits/stdc++.h>
using namespace std;

class Student {
    private:
    int data;
    string name;

    public:
    // getter
    int getData(){
        return this->data;
    }
};

int main(){
    Student first;

    cout<<"All working fine"<<endl;

    return 0;
}


