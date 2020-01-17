#include <iostream>
#include <cstddef>
#include "MyLinkedList.h"

using namespace std;

MyLinkedList::MyLinkedList() {
    head = NULL;
    tail = NULL;
}

void MyLinkedList::display() {
    node *cur {head};
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int MyLinkedList::get(int index) {
    int count {0};
    node *cur {head};
    while(cur != NULL) {
        if(count == index) {
            cout << cur->data << endl;
            return(cur->data);
        }
        count++;
        cur = cur->next;
    }
    return -1;
}

void MyLinkedList::addAtHead(int val) {
    node *cur = new node;
    cur->data = val;
    if(head == NULL) {
        cur->next = NULL;
        head = cur;
        tail = cur;
    } else {
        cur->next = head;
        head = cur;
    }
}

void MyLinkedList::addAtTail(int val) {
    node *cur = new node;
    cur->data = val;
    cur->next = NULL;
    if(head == NULL) {
        head = cur;
        tail = cur;
    } else {
        tail->next = cur;
        tail = cur;
    }
}

void MyLinkedList::addAtIndex(int index, int val) {
    if(index == 0) {
        addAtHead(val);
    } else {
        int count {0};
        node *cur {head};
        while(cur != NULL) {
            if(count == index - 1) {
                if(cur->next == NULL) { 
                    addAtTail(val);
                } else {
                    node *tmp = new node;
                    tmp->data = val;
                    tmp->next = cur->next;
                    cur->next = tmp;
                }
            }
            count++;
            cur = cur->next;
        }
    }
}

void MyLinkedList::deleteAtIndex(int index) {
    node *cur {head};
    if(index == 0) {
        head = cur->next; 
    } else { 
        int count {0};
        while(cur != NULL) {
            if((count == index - 1) && (cur->next != NULL)) {
                if(cur->next->next == NULL) 
                    tail = cur;
                cur->next = cur->next->next;
                break;
            }
            count++;
            cur = cur->next;
        }
    }
}