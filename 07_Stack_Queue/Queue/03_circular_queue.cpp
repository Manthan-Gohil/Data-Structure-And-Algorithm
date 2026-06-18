// circular queue
// same as queue and three main operations
// push operation is from the rear end and update the rear end
// pop operation is from the front and update the front
// front value will be got same as queue

// difference from normal queue
// circular queue has a fixed size / capacity
// because it has a fixed capacity so we use array to implement circular queue
#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    int* arr;
    int cap;
    int currentSize;
    int f, r;

    public:
    CircularQueue(int size){
        cap = size;
        arr = new int[cap]; // dynamic memory allocation
        currentSize = 0;
        f = 0; // front
        r = -1; // rear
    }

    void push(int data){
        if(currentSize == cap){
            cout<<"Queue is full"<<endl;
            return;
        }
        r = (r+1) % cap;
        arr[r] = data;
        currentSize++;
    }

    void pop(){
        if(empty()){
            cout<<"Queue is already empty"<<endl;
            return;
        }
        f = (f + 1) % cap;
        currentSize--;
    }

    int front(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return currentSize == 0;
    }

    void printArr(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i=0;i<currentSize;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4); 
    
    // cq.printArr(); // 4,2,3 front = 2 rear = 4

    while(!cq.empty()){
        cout<<cq.front()<<" ";
        cq.pop();
    }


}