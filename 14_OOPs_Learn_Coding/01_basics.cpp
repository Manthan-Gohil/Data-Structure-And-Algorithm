#include<bits/stdc++.h>
using namespace std;

class Person{
    // by default all data member and member function are private (if we explicitly do not give public access specifiers)
    int age;
    string name;
    string address;

    public:
    void input(){
        cout<<"Enter age"<<endl;
        cin>>age;

        cout<<"Enter name"<<endl;
        cin>>name;

        cout<<"Enter address"<<endl;
        cin>>address;
    }
    void output(){
        cout<<"Age : "<<age<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Address : "<<address<<endl;
    }
};

int main(){
    Person obj1,obj2,obj3;

    obj1.input();
    obj1.output();

    obj2.input();
    obj2.output();
   
    obj3.input();
    obj3.output();


}