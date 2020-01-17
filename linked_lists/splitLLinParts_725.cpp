#include <iostream>
#include <cstddef>
#include <stack>
#include <vector>
#include <math.h>
#include "MyLinkedList.h"

using namespace std;

class Solution {
public:
    vector<MyLinkedList::node*> splitListToParts(MyLinkedList::node* root, int k) {
        MyLinkedList::node* cur {root};
        int count {0};
        while(cur) {
            count++;
            cur = cur->next;
        }

        MyLinkedList::node* tmp {root};
        MyLinkedList::node* prev {NULL};
        vector<MyLinkedList::node*> heads;
        if(count < k) count = k;
        double div {ceil((double)count/k)};
        heads.push_back(tmp);
        int i {0};
        while(k > 1) {
            if(i == div && tmp) {
                heads.push_back(tmp);
                prev->next = NULL;
                i = 0;
                k -= 1;
                count -= div;
                div = ceil((double)count/k);
            } else if(!tmp) {
                heads.push_back(NULL);
                k -= 1;
                continue;
            }
            prev = tmp;
            tmp = tmp->next;
            ++i;
        }
        return heads;
    }
};

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(0);
    obj->addAtHead(1);
    obj->addAtHead(2);
    obj->addAtHead(3);
    obj->addAtHead(4);

    MyLinkedList::node* head {obj->head};
    Solution S;
    S.splitListToParts(head,3);
    return 0;
}