#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    // doubly linked list
    public:
    class Node{
        public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int key, int value){
            this->key = key;
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int limit;
    unordered_map<int, Node*> m;

    void addNode(Node* newNode){
        Node* oldNext = head->next;
        head->next = newNode;

        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode){
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity){
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){

        if(m.find(key) == m.end()){ // does not exist
            return -1;
        }
        Node* ansNode = m[key];
        int ans = ansNode->value;
        
        m.erase(key);
        deleteNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;
        
        return ans;
    }

    void put(int key, int value){
        // check key already exist in map
        if(m.find(key) != m.end()){ // exists then remove from map and linked list
            deleteNode(m[key]);
            m.erase(key);
        }
        // if capacity is full then remove LRU data
        if(m.size() == limit){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key,value);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main(){
    
    LRUCache cache(2);

    cache.put(1, 1);
    cout << "put(1,1)" << endl;

    cache.put(2, 2);
    cout << "put(2,2)" << endl;

    cout << "get(1) = " << cache.get(1) << endl; // 1

    cache.put(3, 3);
    cout << "put(3,3)" << endl;

    cout << "get(2) = " << cache.get(2) << endl; // -1

    cache.put(4, 4);
    cout << "put(4,4)" << endl;

    cout << "get(1) = " << cache.get(1) << endl; // -1
    cout << "get(3) = " << cache.get(3) << endl; // 3
    cout << "get(4) = " << cache.get(4) << endl; // 4

    return 0;

}