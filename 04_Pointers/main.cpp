#include<bits/stdc++.h>
using namespace std;

// memory address -> address are stored in hexadecimal format (16 digits) in memory
// e.g, Ox36a6
// to print the memory address, we use "address of operator"(&)
// e.g, int a = 10; cout<<&a;

// & can be used as bitwise operator or address of operator

// pointers -> special variables used to store address of another variable
// pointers have same datatype of which the variable address it stores. 

// pass by reference using pointer
void changeValue(int* ptr){
    *ptr = 20;
}

// pass y reference using references/alias
int changeValue2(int &b){
    b = 30;
    return b;
}
int main(){
    int a = 10;
    // address of operator
    cout<< &a <<endl;
    // ptr = &a
    // pointers
    int* ptr = &a;
    cout<<"Address of variable a "<<ptr<<endl;
    cout<<"Value of variable a "<<*ptr<<endl;
    cout<<"Address of pointer "<<&ptr<<endl;

    // different datatype pointer
    float price = 100.25;
    float* ptr2 = &price;
    cout<<ptr2<<endl;
    cout<<&price<<endl;

    // pointer to pointer -> a pointer which stores the address of another pointer 
    int** ptr3 = &ptr ;
    cout<< &ptr <<endl;
    cout<< ptr3 <<endl; // same value as &ptr

    // * dereference operator -> value at address
    cout<<"value of a using dereference operator "<<*(&a)<<endl; // 10
    cout<<"value at pointer address using dereference operator "<<*(ptr)<<endl; // 10

    cout<<"value at pointer-to-pointer address using dereference operator "<<*(ptr3)<<endl; 
    cout<<"value at pointer address "<<(ptr)<<endl; 
    cout<<"double dereference operator on pointer-to-pointer "<<**(ptr3)<<endl; // 10


    // NULL pointer -> pointer which do not point any address
    int* ptr4 = NULL;
    cout<<"Null Pointer -> "<<ptr4<<endl;
    // we can not do dereference of null value like *(ptr4) 
    // cout<<*(ptr4)<<endl;

    // Question
    int val = 5;
    int *p = &val;
    int **q = &p;

    cout<< *p <<endl; // value at address of val // 5
    cout<< **q <<endl; // value at this address -> (value at address of p) // 5
    cout<< p <<endl; // address of val // e.g, 0x62fef0
    cout<< *q <<endl; // value at address of p // 0x62fef0

    // pass by reference -> same value change in the function passes as parameter in the main function (do not make copy of that variable)
    // it happen in two types either will be using pointers or references/alias
    // e.g, pointer vala
    int value = 10;

    changeValue(&value);
    cout<<"pass by reference using pointers "<<value<<endl;

    // another method to implement pass by reference is using references/alias
    cout<<"pass by refernce using reference/alias "<<changeValue2(value)<<endl;

    // array pointer
    // name of the array is the pointer which stores the address of array at index 0
    // e.g,
    int arr[] = {1,2,3,4,5};
    cout<< arr <<endl;
    cout<< *arr <<endl;

    // array pointer is constant pointer means its value will never be changed
    // arr = &a; // (error)

    // pointer arithmetic
    // p++ means it increament its value of how much byte datatype is
    // eg, for interger if its value is 100 then p++ will be 104
    cout<<ptr<<endl;
    ptr++;
    cout<<ptr<<endl; // +4 byte

    // similarly ptr = ptr + 2 means adding 8 byte value
    cout<<*(arr)<<endl;
    cout<<*(arr+1)<<endl;
    cout<<*(arr+2)<<endl;

    int* ptr6 = ptr + 2;
    cout<< (ptr6 - ptr) <<endl; // 2 bytes

    // Question
    int arr2[] = {10,20,30,40};
    int* ptr5 = arr2;

    cout<<*(ptr5+1)<<endl; // 20
    cout<<*(ptr5+3)<<endl; // 40
    ptr5++;
    cout<<*ptr5<<endl; // 20
    return 0;
}


