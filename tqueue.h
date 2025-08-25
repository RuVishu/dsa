#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class TQueue {
private:
    T* tarr;
    int tfront, trear, tcapacity;
    int tcount;  // to keep track of the number of elements in the queue

public:
    // Constructor to initialize queue
    TQueue(int size) {
        tarr = new T[size];
        tcapacity = size;
        tfront = 0;
        trear = -1;
        tcount = 0;
    }

    // Destructor to free memory
    ~TQueue() {
        delete[] tarr;
    }

    // Enqueue (insert) element into the queue
    void tenqueue(T x) {
        if (tisFull()) {
            cout << "Queue Overflow. Queue is full.\n";
            return;
        }
        trear = (trear + 1) % tcapacity; // circular increment
        tarr[trear] = x;
        tcount++;
    }

    // Dequeue (remove) element from the queue
    T tdequeue() {
        if (tisEmpty()) {
            cout << "Queue Underflow. Queue is empty.\n";
            return -1;
        }
        T element = tarr[tfront];
        tfront = (tfront + 1) % tcapacity; // circular increment
        tcount--;
        return element;
    }

    // Peek at the front element without removing it
    T tfrontel() {
        if (tisEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return tarr[tfront];
    }

    // Peek at the rear element without removing it
    T trearel() {
        if (tisEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return tarr[trear];
    }

    // Check if the queue is empty
    bool tisEmpty() {
        return tcount == 0;
    }

    // Check if the queue is full
    bool tisFull() {
        return tcount == tcapacity;
    }

    // Return the number of elements in the queue
    int tsize() {
        return tcount;
    }

    // Print all elements in the queue
    void tprint() {
        if (tisEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < tcount; i++) {
            int index = (tfront + i) % tcapacity;
            cout << tarr[index] << " ";
        }
        cout << endl;
    }
};

#endif

