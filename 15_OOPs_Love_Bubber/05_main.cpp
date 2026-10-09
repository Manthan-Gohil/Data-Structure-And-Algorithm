// copy assignment operator
// two different objects, obj1 = obj2 then all values of obj1 will be replaced by obj2 value
// e.g,
#include<bits/stdc++.h>
using namespace std;

class Hero {
    public:
    int health;
    char level;

    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }

    void print(){
        cout<<"[Health : "<<this->health<<", ";
        cout<<"Level : "<<this->level<<"]";
        cout<<endl;
    }
};

int main(){

    Hero h1(50,'A');

    // h1.print();

    
    Hero h2(h1);
    // h2.print();

    h1.health = 100;
    h1.print();
    h2.print(); 

    h1 = h2; // copy assignment operator
    h1.print();
    h2.print();
}