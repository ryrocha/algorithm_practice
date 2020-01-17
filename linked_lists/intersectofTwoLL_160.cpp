#include <iostream>
#include <cstddef>
#include <unordered_map>
#include "MyLinkedList.h"

using namespace std;

class Solution {
public:
    MyLinkedList::node* getIntersectionNode(MyLinkedList::node* headA, MyLinkedList::node* headB) {
        unordered_map<MyLinkedList::node*, int> mapA;
        MyLinkedList::node* curA {headA};
        MyLinkedList::node* curB {headB};
        while(curA) {
            mapA.insert(make_pair(curA, 1));
            curA = curA->next;
        }
        while(curB) {
            if(mapA.find(curB) != mapA.end())
                return curB;
            curB = curB->next;
        }
        return NULL;
    }
    
    // optimal is to maintain two pointers starting at the head of each list
    // when the pointers reach the end of either list switch them to the head of the other list
    // they will meet at some point and that will be the intersection point
    // similar to the fast slow pointer approach
};

int main() {
    return 0;
}