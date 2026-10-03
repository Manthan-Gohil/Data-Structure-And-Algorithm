// copy constructor -> a constructor that is used to copy or initialize the value of one object into another object is called copy constructor.

#include<bits/stdc++.h>
using namespace std;

// When is a Copy Constructor Called?
// It runs automatically in three situations:

// Direct Copy Initialization: Student s2 = s1; or Student s2(s1);
// Passed by Value: Passing an object into a function.
// Returned by Value: Returning an object from a function.

// Variation 1: Default (Shallow) Copy Constructor
// If you don't write a copy constructor, C++ automatically creates one for you. It copies every member variable as-is. This works fine for basic variables like int, float, and string.
// Variation 2: Deep Copy Constructor (Handling Dynamic Memory)
// When a class manages dynamic memory allocated with new, the default shallow copy only copies the memory address (pointer). Both objects end up pointing to the same memory location, which leads to crashes or double-free errors when destructors run.

// A Deep Copy allocates a separate block of memory for the new object and copies the actual values.

class A {
public:
    string name;
    int age;

    // Parameterized Constructor
    A(string n, int a){
        name = n;
        age = a; 
    }
    A(A &ref){ // copy constructor
        name = ref.name;
        age = ref.age;
    }
    void show(){
        cout<<"name = "<<name<<" age = "<<age<<endl;
    }
};

int main() {

    A obj("Manthan", 22);
    obj.show();

    A obj2 = obj; // calling the copy contructor
    obj2.show();


    
}
