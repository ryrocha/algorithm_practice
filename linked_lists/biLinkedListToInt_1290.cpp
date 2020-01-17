#include <iostream>
#include <cstddef>
#include "MyLinkedList.h"

using namespace std;

class Solution {
public:
    int getDecimalValue(MyLinkedList::node* head) {
        MyLinkedList::node *cur {head};
        unsigned int num {0};
        while(cur != NULL) {
            num ^= cur->data;
            if(cur->next != NULL) 
                num <<= 1;
            cur = cur->next;
        }
        cout << num << endl;
        return num;
    }
};

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtHead(0);
    obj->addAtHead(1);
    obj->addAtHead(1);
    obj->display();

    MyLinkedList::node* head {obj->head};
    Solution S;
    S.getDecimalValue(head);
    return 0;
}