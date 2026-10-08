// OOPs -> it is a type of programming style/technique/paradigm where whole things revolve around the objects.

// Object -> it is the entity which has its state/property and behaviour. It is an instance of class.

// Why OOPs? 
// because to increase the readability, manageability, extensibility of program.

// class -> class is a blueprint/template used to create an object. It is a user-defined datatype

// Access modifies -> kisi bhi data members or behaviour ko kaha tk access kr payenge?
// three types of access modifiers
// public: data members and behaviour are accessible throughout the program
// private: only accesssible inside the class (but can be accessible outside the class using getter and setter function)
// protected: child class accessible (used in inheritance concept)

#include<bits/stdc++.h>
using namespace std;

class Hero{

    // properties
    public:
    int health;

    private:
    int level;

    void print(){
        cout<<level<<endl;
    }

};

int main(){
    // creation of object
    Hero h1;

    cout<<"Size of object h1 = "<<sizeof(h1)<<endl; // object ki size utni hi hogi jitni uske ander total sum of properties/variables ko size milti hai
    // Note -> empty class ke case me uske object ko 1 byte ki memory allocate hogi


    // access the variables from class using object (using dot operator)
    // Note -> by default all variables are private means they can not be accessible outside of the class
    // cout<<h1.level<<endl; // error
    cout<<h1.health<<endl; // shows garbase value not error because it is public
}
