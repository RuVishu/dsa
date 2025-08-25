#ifndef DEQUE_H
#define DEQUE_H

class deque
{
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    deque(int size);
    ~deque();

    void insertFront(int x);
    int delFront();
    void insertBack(int x);
    int delBack();
    bool isEmpty();
    bool isFull();
    int dqsize();
    void dqprint();
    int frontd();
    int reard();
};

#endif

