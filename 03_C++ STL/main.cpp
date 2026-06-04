// algorithm
// container
// functions
// iterator
#include<bits/stdc++.h>
using namespace std;

// pairs
 void explainPairs(){
    pair<int,int> p = {1,3};
    cout<<p.first<<" "<<p.second<<endl;

    pair<int, pair<int,int>> p2 = {1, {2,3}};
    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second<<endl;

    pair<int,int> arr[] = {{1,2}, {3,4}, {5,6}};
    cout<<arr[1].second;
 }

// vectors

void explainVectors(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2); // v = {1,2}
    vector<pair<int,int>> vec;
    
    vec.push_back({1,2});
    vec.emplace_back(2,3); // vec = {{1,2}, {2,3}}

    vector<int> v3(5,100); // v3 = {100,100,100,100,100}

    vector<int>  v4(5);
    vector<int> v1(5,20); // v1 = {20,20,20,20,20}
    vector<int> v2(v1); // copy of vector v2 = v1

    v.push_back(3);
    v.push_back(4);
    v.push_back(5); // v = {1,2,3,4,5}

    vector<int> ::iterator it = v.begin();
    it++;
    cout<<*(it)<<endl; // gives second element because of it++ // 2 ans

    it = it+2;
    cout<<*(it)<<endl; // 4 ans

    vector<int>::iterator its = v.end(); //v.end() points next last of the vector data (also 'it' points the memory address )

    // vector<int>::iterator it = v.rend();

    // vector<int>::iterator it = v.rbegin();

    cout<<v[0]<<" "<<v.at(0)<<endl; // v[0] is same as v.at(0)

    cout<<"v.back() "<<v.back()<<endl; // print the last element in vector data
    cout<<"v.front() "<<v.front()<<endl; // print the first element in the vector data 

    // iterator
    for(vector<int>::iterator it=v.begin(); it!= v.end();it++){ // it points the memory address 
        cout<<*(it)<<" "; // for getting value we need to use pointer
    }
    cout<<endl;

    for(auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;

    // {10,20,30,40}
    v.erase(v.begin()+1); // delete the 20 element

    //{10,20,12,23,35}
    v.erase(v.begin()+2, v.begin()+4); // delete the element from 12 to 23 [first,last)

    // insert function
    vector<int> v5(2,100); // {100,100}
    v5.insert(v5.begin(), 300); // {300,100,100}
    v5.insert(v5.begin()+1, 2, 10); // {300,10,10,100,100}

    vector<int>copy(2,50); // {50,50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50,50,300,10,10,100,100}

    // {10,20}
    cout<<v.size()<<endl; // 2
    // {10,20}
    v.pop_back(); // {10}

    // v1 = {10,20}
    // v2 = {30,40}
    v1.swap(v2); // v1-> {30,40} v2-> {10,20}

    v1.clear(); //erase the entire vector

    cout<<v.empty(); // gives boolean value(false,true) if vector has no data then it gives true as an output
}

void explainLists(){
    cout<<"lists starts:"<<endl;
    list<int> ls;
    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); // {5,2,4}
    ls.emplace_front(2);  // {2,5,2,4}
    cout<<"list are = ";
    for(auto it: ls){
        cout<<it<<" ";
    }
    cout<<endl;
    // rest functions are the same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void explainDeque(){
    cout<<"Dequeue starts:"<<endl;
    deque<int> dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1,2}
    dq.push_front(4); // {4,1,2}
    dq.emplace_front(3); // {3,4,1,2}

    dq.pop_back(); // {3,4,1}
    dq.pop_front(); // {4,1}

    cout<<"deque are = ";
    for(auto it: dq){
        cout<<it<<" ";
    }
    cout<<endl;
    dq.back();

    dq.front();

    // rest functions are the same as vectors
    // begin, end, rbegin, rend, clear, insert, size, swap

}

void explainStack(){
    cout<<"Stack starts:"<<endl;
    // stack follow LIFO 
    stack<int> st;
    // METHOD-> push, pop, top, empty, size
    st.push(1); // {1}
    st.push(2); // {2,1}
    st.push(3); // {3,2,1}
    st.push(3); // {3,3,2,1}
    st.emplace(5); // {5,3,3,2,1}

    cout<<"top of stack: "<<st.top()<<endl;
    
    st.pop();
    
    cout<<st.top()<<endl;

    cout<<st.size()<<endl;

    cout<<st.empty()<<endl;
    
    cout<<endl;
    stack<int> st1,st2;
    st1.swap(st2);

}

void explainQueue(){
    // queue follow FIFO property
    cout<<"Queue starts:"<<endl;
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() +=5; 

    cout<<q.back()<<endl; // print 9

    // 0 is {1,2,9}
    cout<<q.front()<<endl; // print 1

    q.pop(); // {2,9}

    cout<<q.front()<<endl; // prints 2

    // size swap empty same as stack
}

void explainPQ(){
    cout<<"Priority Queue starts:"<<endl;
    // max heap(by default)
    priority_queue<int> pq;

    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); // {10,8,5,2}

    cout<<pq.top()<<endl; //print 10

    pq.pop(); // {8,5,2}

    cout<<pq.top()<<endl; // print 8

    // size swap empty function same as others

    // minimum heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.emplace(10); // {2,5,8,10}

    cout<<pq.top()<<endl; //print 2

}

void explainSet(){
    cout<<"Set starts:"<<endl;
    // sets are sorted and unique by default
    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1,2}
    st.insert(2); // {1,2}
    st.insert(3); // {1,2,3}
    st.insert(4); // {1,2,3,4}

    // functionality of insert in vector
    // can be used also, that only increases
    // efficiency

    // begin(), end(), rbegin(), rend(), size(),
    // empty() and swap() are same as those of above

    // {1,2,3,4,5}
    auto it = st.find(3);

    // {1,2,3,4,5}
    auto it = st.find(6);

    // {1,4,5}
    st.erase(5); // erase 5 // takes logarithmic time

    int cnt = st.count(1);

    auto it = st.find(3);
    st.erase(it); // it takes constant time

    // {1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2); // after erase {1,4,5} [first, last)


    // lower_bound() and upper_bound() function works in the same way
    // as in vector it does

    // this is the syntax
    auto it = st.lower_bound(2);

    auto it = st.upper_bound(3);
}

void explainMultiSet(){
    cout<<"Multiset starts:"<<endl;
    // Everything is same as set
    // only stores duplicate elements also

    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(1); //{1,1,1}

    ms.erase(1); // all 1's erased

    int cnt = ms.count(1);

    // only a single one erased
    ms.erase(ms.find(1));

    // ms.erase(ms.find(1), ms.find(1)+2);

    // rest all function same as set
}

void explainUSet(){
    cout<<"Unordered set starts:"<<endl;
    unordered_set<int> st;
    // lower_bound and upper_bound function
    // does not work, rest all functions are same
    // as above, it does not store in any
    // perticular order it has a better complexity
    // than set in most cases, except some when collision happens
}

void explainMap(){
    cout<<"Map starts"<<endl;
    // map is key value pair where key is unique
    map<int,int> mpp;

    map<int, pair<int,int>> mapp;

    map<pair<int,int>, int> mpp;

    mpp[1] = 2; // {1,2}
    mpp.emplace(3,1); // {3,1}
    mpp.insert({2,4}); // {2,4}

    // mpp[{2,3}] = 10;

    for(auto it: mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<mpp[1];
    cout<<mpp[5];

    auto it = mpp.find(3);
    // cout<< *(it).second <<endl;

    auto it = mpp.find(5);

    // this is the syntax
    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty, are same as above
}

void explainMultiMap(){
    // everything is same as map, only it can store multiple keys
    // only mpp[key] cannot be used here
}

void explainUnorderedMap(){
    // same as set and unordered set difference
}

void explainExtra(){
    int a[4] = {1,5,6,3};
    sort(a, a+4);

    vector<int> v = {1,5,8,2};
    sort(v.begin(), v.end());

    sort(a+2, a+4);

    // sort(a, a+2, greater<int>);
}

int main(){

    // explainPairs();
    explainVectors();
    explainLists();
    explainDeque();
    explainStack();
    explainQueue();
    explainPQ();
    explainSet();
    explainMultiSet();
    explainUSet();
    explainMap();
    explainExtra();
}