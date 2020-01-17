#include <iostream>
#include <cstddef>
#include <string>
#include <stack>
#include "MyLinkedList.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(MyLinkedList::node* head) {
        /** This solution uses too much memory by storing two strings 
        MyLinkedList::node* cur {head};
        string ord {""};
        string rev {""};
        while(cur != NULL) {
            string num {to_string(cur->data)};
            ord = ord + num;
            rev = num + rev;
            cur = cur->next;
        }
        return(ord == rev);
        **/

        // pursued after seeing solution (stack approach)
        stack<int> nums;
        MyLinkedList::node* cur {head};
        MyLinkedList::node* comp {head};
        while(cur) {
            nums.push(cur->data);
            cur = cur->next;
        }
        while(comp) {
            if(nums.top() == comp->data)
                nums.pop();
            comp = comp->next;
        }
        return nums.empty();

        // a faster soultion would be to construct a vector 
        // then check for palindrome using two pointer
    }
};

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(-1);
    obj->addAtHead(0);
    obj->addAtHead(1);
    obj->addAtHead(-1);
    obj->display();

    MyLinkedList::node* head {obj->head};
    Solution S;
    cout << S.isPalindrome(head) << endl;
    return 0;
}