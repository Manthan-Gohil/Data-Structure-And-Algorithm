// shallow copy and deep copy
// Shallow copy and deep copy are very important in C++ OOP, especially when a class contains pointers/dynamically allocated memory.
// Shallow copy → copies the address
// Deep copy → copies the actual data into a new memory location

// shallow copy
// 1. Copies the pointer/address
// 2. Both objects may share same data
// 3. Changes can affect the other object
// 4. Usually problematic with dynamic memory
// 5. Default copy constructor can perform this for raw pointers

// deep copy
// 1. Creates new memory
// 2. Objects have independent data
// 3. Changes don't affect the other object
// 4. Safer for owning dynamic memory
// 5. Requires custom copying logic

// default copy constructor shallow copy krta hai

// e.g, of shallow copy using default copy constructor
// #include<bits/stdc++.h>
// using namespace std;

// class Hero {
//     public:
//     int health;
//     char level;
//     char* name;

//     Hero(){
//         name = new char[100]; // dynamic memory allocation (store in heap memory)
//     }

//     void setHealth(int health){
//         this->health = health;
//     }

//     void setLevel(char ch){
//         this->level = ch;
//     }

//     void setName(char name[]){
//         this->name = name;
//     }

//     void print(){
//         cout<<"[Name : "<<this->name<<", ";
//         cout<<"Health : "<<this->health<<", ";
//         cout<<"Level : "<<this->level<<"]";
//         cout<<endl;
//     }
// };

// int main(){

//     Hero h1;
//     h1.setHealth(50);
//     h1.setLevel('A');
//     char name[8] = "Manthan";
//     h1.setName(name);

//     h1.print();

//     // using default copy constructor
//     Hero h2(h1);
//     // Hero h2 = h1 // this is also correct
//     h2.print();

//     h1.name[0] = 'P';
//     h1.print();
//     h2.print(); // this is the problem with shallow copy if i change the value in h1 object then h2 also changes its value
//     // in shallow copy, both objects h1 and h2 has name pointer which points to same memory address due to which if one of the name is changed then it also keep its effect on second object as well. 
// }


// deep copy example (using manually created copy constructor)
#include<bits/stdc++.h>
using namespace std;

class Hero {
    public:
    int health;
    char level;
    char* name;

    // default constructor
    Hero(){
        name = new char[100];
    }

    // manually created copy constructor
    Hero(Hero &temp){
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch,temp.name);
        this->name = ch;

        cout<<"copy constructor called : "<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void setHealth(int health){
        this->health = health;
    }

    void setLevel(char ch){
        this->level = ch;
    }

    void setName(char name[]){
        this->name = name;
    }

    void print(){
        cout<<"[Name : "<<this->name<<", ";
        cout<<"Health : "<<this->health<<", ";
        cout<<"Level : "<<this->level<<"]";
        cout<<endl;
    }
};

int main(){

    Hero h1;
    h1.setHealth(50);
    h1.setLevel('A');
    char name[8] = "Manthan";
    h1.setName(name);

    h1.print();

    
    Hero h2(h1);
    h2.print();

    h1.name[0] = 'P';
    h1.print();
    h2.print(); // this is deep copy if i change the value in h1 object then h2 does not changes its value
    // in deep copy, both objects h1 and h2 has name pointer which points to different memory address 
}