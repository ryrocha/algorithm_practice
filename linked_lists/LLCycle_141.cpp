#include <iostream>
#include <cstddef>
#include <unordered_map>
#include "MyLinkedList.h"

using namespace std;

class Solution {
public:
    bool hasCycle(MyLinkedList::node* head) {
        // brute force using unordered map
        unordered_map<MyLinkedList::node*, int> map;
        MyLinkedList::node* cur {head};
        while(cur) {
            map.insert(make_pair(cur, 1));
            if(map.find(cur->next) != map.end()) 
                return true;
            cur = cur->next;
        }
        return false;

        // slow fast pointer approach is more optimal
        // fast pointer moves twice as fast as slow
        // pointers will meet if there is a loop
    }
};

int main() {
    return 0;
}