// Padding is the extra memory inserted by the compiler between or after data members of a class/structure to satisfy their alignment requirements.

// Alignment is the requirement that objects of a particular type should start at suitable memory addresses, usually a multiple of the type's alignment.

// Greedy alignment refers to the compiler's layout strategy of placing each data member at the earliest address that satisfies its alignment requirement, while maintaining the declared order of members.



#include<bits/stdc++.h>
using namespace std;

class Hero {
    private:
    int health;

    public:
    char level;

    void print(){
        cout << level << endl;
    }

    // getter
    int getHealth(){
        return health;
    }
    // getter
    char getLevel(){
        return level;
    }
    // setter
    void setHealth(int h){
        health = h;
    }
    // setter
    void setLevel(char ch){
        level = ch;
    }
};

int main(){
    Hero ramesh;

    // garbage values
    cout<<"health is " << ramesh.getHealth() << endl;
    cout<<"level is " << ramesh.level << endl;

    // use setter
    ramesh.setHealth(70);
    ramesh.level = 'A';

    cout<<"health is " << ramesh.getHealth() << endl;
    cout<<"level is " << ramesh.level << endl;

    cout << "Size of object : "<< sizeof(ramesh) << endl; // why 8 and why not 5 (because of padding and greedy alignment)
    // 3. Why does the compiler add padding?
    // The main reason is efficient memory access.
    // Modern CPUs generally access certain data types more efficiently when they are stored at properly aligned addresses.


    // static and dynamic memory allocation
    cout<<"Static and Dynamic memory : "<<endl;
    // static allocation
    Hero a;
    a.setHealth(60);
    a.setLevel('A');
    cout<<"level is "<<a.level<<endl;
    cout<<"health is "<<a.getHealth()<<endl;

    // dynamically
    Hero* b = new Hero; // b is a pointer of Hero type which store the address of object. value of object can be accessed using dereference operator (*b)
    b->setHealth(70);
    b->setLevel('B');
    cout<<"level is "<<(*b).level<<endl;
    cout<<"health is "<<(*b).getHealth()<<endl;

    // or
    cout<<"level is "<<b->level<<endl;
    cout<<"health is "<<b->getHealth()<<endl;
}