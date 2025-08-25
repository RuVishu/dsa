#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size);
    ~Queue();

    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    bool isFull();
    int qsize();
    void qprint();
    int frontel();
    int rearel();
};

#endif

