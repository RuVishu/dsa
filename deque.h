#ifndef DEQUE_H
#define DEQUE_H

#include "DOUBLY.H"  

class deque
{
private:
    doubly a; // Using the doubly class to manage the deque operations
    int n;    // Maximum size of the deque

public:
    deque(int size);
    ~deque();

    void insertFront(int x);
    void  delFront();
    void insertBack(int x);
    void  delBack();
    bool isEmpty();
    bool isFull();
    int dqsize();
    void dqprint();
    int frontd();
    int reard();
};

#endif // DEQUE_H

