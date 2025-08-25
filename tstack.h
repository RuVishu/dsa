#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>
using namespace std;

template <typename T>
class TStack {
private:
    T* tarr;
    int ttop;
    int tcapacity;

public:
    TStack(int size) {
        tarr = new T[size];
        tcapacity = size;
        ttop = -1;
    }

    ~TStack() {
        delete[] tarr;
    }

    void tpush(T x) {
        if (tisFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        tarr[++ttop] = x;
    }

    T tpop() {
        if (tisEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return tarr[ttop--];
    }

    T tpeek() {
        if (tisEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return tarr[ttop];
    }

    bool tisEmpty() {
        return ttop == -1;
    }

    bool tisFull() {
        return ttop == tcapacity - 1;
    }

    void tprint() {
        if (tisEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack:\n";
        for (int i = ttop; i >= 0; i--) {
            cout << tarr[i] << " ";
        }
        cout << endl;
    }

    int tsize() {
        return ttop + 1;
    }
};

#endif

