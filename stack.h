#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size);
    ~Stack();

    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
    void print();
    bool search(int el);
};

#endif

