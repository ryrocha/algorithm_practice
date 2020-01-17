#include <iostream>
#include <cstddef>

using namespace std;

class MyLinkedList {
public:
    struct node {
        int data;
        node *next;
    };
    
    node *head, *tail;

    MyLinkedList(); 
    void display(); 
    int get(int index); 
    void addAtHead(int val); 
    void addAtTail(int val); 
    void addAtIndex(int index, int val); 
    void deleteAtIndex(int index); 
};