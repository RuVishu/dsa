#include <iostream>
using namespace std;

class cnode {
public:
    int data;
    cnode *next;

    // Default constructor
    cnode() {
        data = 0;
        next = NULL;
    }

    // Parameterized constructor
    cnode(int el) {
        data = el;
        next = NULL;
    }
};

class circular {
    cnode *cursor;

public:
    // Constructor
    circular() {
        cursor = NULL;
    }
    
    // Insert element at the back of the list
    void insert_back(int el) {
        cnode *newnode = new cnode(el);
        if (cursor == NULL) {
            cursor = newnode;
            cursor->next = cursor;
            return;
        }
        newnode->next = cursor->next;
        cursor->next = newnode;
        cursor = newnode;
    }

    // Insert element at the front of the list
    void insert_front(int el) {
        cnode *newnode = new cnode(el);
        if (cursor == NULL) {
            cursor = newnode;
            cursor->next = cursor; 
            return;
        }
        newnode->next = cursor->next;
        cursor->next = newnode;
    }

    // Print the list
    void cprint() {
        if (cursor == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        cnode *temp = cursor->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != cursor->next);
        cout << endl;
    }
};

int main() {
    circular cl;
    cl.insert_back(10);
    cl.insert_back(20);
    cl.insert_front(5);
    cl.insert_front(67);
    cl.cprint(); 
    return 0;
}
