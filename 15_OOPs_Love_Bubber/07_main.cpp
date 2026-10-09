// static keyword
// static keyword aaisa data member create krta hai jo ki class ko belong krta hai , matlab is data member ko access krne ke liye hame object bnane ki need nhi hoti hai
// static data member ko class ke bahar initialize krte hai
// e.g, datatype classname :: variable_name = value; 
// e.g, int Hero :: timeToComplete = 5;

// print static keyowrd without creating object
// cout<<Hero:: timeToComplete<<endl;

// #include<bits/stdc++.h>
// using namespace std;

// class Hero {
//     public:
//     int health;
//     char level;
//     static int timeToComplete;

// };

// int Hero :: timeToComplete = 5;
// int main(){

//     cout<<Hero::timeToComplete<<endl; // good approach to call statci data member

//     Hero h1;
//     cout<<"static keyword calling using object : "<<h1.timeToComplete<<endl; // bad , not recommanded
//     h1.timeToComplete = 10;
//     cout<<h1.timeToComplete<<endl;

// }

// static function -> same as static data member 
// object create krne ki need nhi hai
// static function me this keyword nhi hota because this pointer point to current object and hame object ki need hi nhi h static function me
// static function sirf static member ko hi access kr skte hai
#include<bits/stdc++.h>
using namespace std;

class Hero {
    public:
    int health;
    char level;
    static int timeToComplete;


    static int random(){
        return timeToComplete; // static keyword 
        // return health; // error, not static keyword
        // return this->health // error, can not used this keyword 
    }
};

int Hero :: timeToComplete = 5;
int main(){

    cout<< Hero::random()<<endl;

}