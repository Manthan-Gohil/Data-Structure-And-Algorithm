// destructor -> used to de-allocate the memory
// if we are not making the destructor then by default destructor made when we create an object and called at time of object going out of scope

// but we can make destructor manually 
// 1. no return type
// 2. same name as class name
// 3. denoted using ~(tilde)
// 4. no input parameter passed in destructor

// Note : destructor is automatically called for the object which are created statically
// for objects created dynamically, we need to call destructor manually

#include<bits/stdc++.h>
using namespace std;

class Hero {
    public:
    int health;
    char level;

    Hero(){
        cout<<"Constructor called : "<<endl;
    }

    ~Hero(){
        cout<<"Destructor called : "<<endl;
    }
};

int main(){

    // statically
    Hero h1;

    // dynamically
    Hero *h2 = new Hero;
    delete h2; // maually calling destructor for object which is created dynamically

}