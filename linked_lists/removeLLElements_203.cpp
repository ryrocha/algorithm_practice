#include <iostream>
#include <cstddef>
#include "MyLinkedList.h"

using namespace std;

class Solution {
public:
    MyLinkedList::node* removeElements(MyLinkedList::node* head, int val) {
        MyLinkedList::node *cur {head};
        MyLinkedList::node *prev {NULL};
        while(cur != NULL) {
            if(cur->data == val) {
                if(!prev) {
                    head = cur->next;
                    cur = cur->next;
                    continue;
                } else if (!cur->next) {
                    prev->next = NULL;
                } else {
                    prev->next = cur->next;
                    cur = cur->next;
                    continue;
                }
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtTail(1);
    obj->addAtTail(1);
    obj->addAtTail(1);
    // obj->addAtTail(2);
    // obj->addAtTail(6);
    // obj->addAtTail(6);
    // obj->addAtTail(3);
    // obj->addAtTail(4);
    // obj->addAtTail(5);
    // obj->addAtTail(6);
    obj->display();

    Solution S;
    MyLinkedList::node* linklist {S.removeElements(obj->head, 1)};
    MyLinkedList::node *cur {linklist};
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}