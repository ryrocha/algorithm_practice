#include <iostream>
#include <cstddef>
#include "MyLinkedList.h"

using namespace std;

class Solution {
public:
    MyLinkedList::node* reverseList(MyLinkedList::node* head) {
        if(!head) return head;
        MyLinkedList::node* cur {head->next};
        MyLinkedList::node* newhead {head};
        MyLinkedList::node* prev {head};
        while(cur) {
            prev->next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = prev->next;
        }
        return newhead;

        // recursive approach after seeing solution:
        // function is recursively called until the last node is reached and assigned the new head
        // the input node of the previous function call is the node just before the last
        // the .next.next of that node points to null which is reassigned to point to itself
        // the .next of the that node is then assigned to null
        // this process repeats itself for each previous function call
        // node.next.next = node; node.next = null; traversing the list backward
        // until the original head node points to null and the list is reversed 
        if (head == NULL || head.next == NULL) return head;
        MyLinkedList::node* newhead = reverseList(head.next);
        head.next.next = head;
        head.next = NULL;
        return newhead;
    }
};

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(0);
    obj->addAtHead(1);
    obj->addAtHead(2);
    obj->addAtHead(3);
    obj->addAtHead(4);
    obj->display();

    Solution S;
    MyLinkedList::node* linklist {S.reverseList(NULL)};
    MyLinkedList::node* cur {linklist};
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}