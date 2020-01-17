#include <iostream>
#include <cstddef>
#include "MyLinkedList.h"

using namespace std;

class Solution {
public:
    MyLinkedList::node* swapPairs(MyLinkedList::node* head) {
        if(!head || !head->next) return head;
        MyLinkedList::node* prev {head};
        MyLinkedList::node* cur {head->next};
        MyLinkedList::node* tmp {head->next->next};
        MyLinkedList::node* newhead {cur};
        while(cur) {
            if(!cur->next || !tmp->next) { 
                cur->next = prev;
                prev->next = tmp;
                break;
            }
            prev->next = cur->next->next;
            cur->next = prev;
            cur = prev->next;
            prev = tmp;
            tmp = cur->next;
        }
        return newhead;
    }
};

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(4);
    obj->addAtHead(3);
    obj->addAtHead(2);
    obj->addAtHead(1);
    obj->addAtHead(1);

    Solution S;
    MyLinkedList::node* linklist {S.swapPairs(NULL)};
    MyLinkedList::node* cur {linklist};
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
    return 0;
}