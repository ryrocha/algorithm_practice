#include <iostream>
#include <cstddef>

using namespace std;

struct node {
    int data;
    node *next;
};

class MyLinkedList {
private:
    node *head, *tail;

public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void display() {
        node *cur {head};
        while(cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    int get(int index) {
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

    void addAtHead(int val) {
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

    void addAtTail(int val) {
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

    void addAtIndex(int index, int val) {
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

    void deleteAtIndex(int index) {
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
};

int main () {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(0);
    obj->display();
    obj->addAtIndex(1, 4);
    obj->display();
    obj->addAtTail(8);
    obj->addAtHead(5);
    obj->display();
    obj->addAtIndex(4, 3);
    obj->addAtTail(0);
    obj->addAtTail(5);
    obj->display();
    obj->addAtIndex(6, 3);
    obj->display();
    obj->deleteAtIndex(7);
    obj->display();
    obj->deleteAtIndex(5);
    obj->addAtTail(4);
    obj->display();
    
    return 0;
}