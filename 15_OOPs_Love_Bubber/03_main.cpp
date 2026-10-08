// constructor
// constructor invoked whenever we create an object
// constructor has no return type
// same name as class name
// whenever we create a object then if we have not create a constructor then by default, default constructor is created


// this-> this is the pointer which always points/store the address of the current object


// Note : if we made a constructor by ourself then the default constructor will be removed permanently and object of that constructor which we made will be created only

// copy constructor (used to copy an object into another object)

#include<bits/stdc++.h>
using namespace std;

class Hero {
    
    public:
    int health;
    char level;

    // constuctor
    Hero() {
        cout<<"Constructor called "<<endl;
    }

    // parametrized constructor
    Hero(int health){
        cout<<"this -> "<<this<<endl;
        this->health = health;
    }

    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }

    // copy constructor
    Hero(Hero &temp){
        cout<<"Copy constructor called : "<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout<<"health : "<<this->health<<endl;
        cout<<"level : "<<this->level<< endl;
    }

};

int main(){
    // object created statically
    Hero ramesh; // by default, default constructor is created
    Hero suresh(10); 

    cout<<"Address of suresh : "<<&suresh<<endl;


    // dynamically
    Hero *h = new Hero;
    Hero *h2 = new Hero(10);

    // copy constructor
    cout<<"Copy constructor : "<<endl;
    Hero R(70,'C');
    R.print();

    Hero S(R); // S object ke ander saari values R ki copy ho jayengi 
    S.print();
    // Note : if we have not create a copy constructor in class then by default, default copy constructor is created and called

    // can we create khud ka copy constructor? Yes by creating a copy constructor in class


}