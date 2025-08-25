#include "DEQUE2.H"
#include <iostream>
using namespace std;

// Node constructor
node::node(int el) {
    data = el;
    prev = next = nullptr;
}

// Deque constructor
deque2::deque2() {
    frontNode = nullptr;
    rearNode = nullptr;
}

// Deque destructor
deque2::~deque2() {
    node* temp = frontNode;
    while (temp != nullptr) {
        node* nextNode = temp->next; 
        delete temp;
        temp = nextNode;
    }
}

// Get the front element of the deque
int deque2::getFront() {
    if (frontNode == nullptr) {
        cout << "Deque is empty!" << endl;
        return -1; // Indicate that the deque is empty
    }
    return frontNode->data;
}

// Get the rear element of the deque
int deque2::getRear() {
    if (rearNode == nullptr) {
        cout << "Deque is empty!" << endl;
        return -1; // Indicate that the deque is empty
    }
    return rearNode->data;
}

// Insert an element at the front
void deque2::insert_f(int el) {
    node* newNode = new node(el);
    if (frontNode == nullptr) {
        frontNode = rearNode = newNode;
    } else {
        newNode->next = frontNode;
        frontNode->prev = newNode;
        frontNode = newNode;
    }
}

// Insert an element at the rear
void deque2::insert_r(int el) {
    node* newNode = new node(el);
    if (rearNode == nullptr) {
        frontNode = rearNode = newNode;
    } else {
        newNode->prev = rearNode;
        rearNode->next = newNode;
        rearNode = newNode;
    }
}

// Delete an element from the front
void deque2::del_f() {
    if (frontNode == nullptr) {
        cout << "Deque is empty!" << endl;
        return;
    }
    node* temp = frontNode;
    if (frontNode == rearNode) {
        frontNode = rearNode = nullptr; // If only one element
    } else {
        frontNode = frontNode->next;
        frontNode->prev = nullptr;
    }
    delete temp;
}

// Delete an element from the rear
void deque2::del_r() {
    if (rearNode == nullptr) {
        cout << "Deque is empty!" << endl;
        return;
    }
    node* temp = rearNode;
    if (frontNode == rearNode) {
        frontNode = rearNode = nullptr; // If only one element
    } else {
        rearNode = rearNode->prev;
        rearNode->next = nullptr;
    }
    delete temp;
}

// Get the size of the deque
int deque2::size() {
    int count = 0;
    node* current = frontNode;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Print the deque from front to rear
void deque2::print_d() {
    node* current = frontNode;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

