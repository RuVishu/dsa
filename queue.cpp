#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = rear = -1;
}

Queue::~Queue() {
    delete[] arr;
}

bool Queue::isEmpty() {
    return front == -1;  
}

bool Queue::isFull() {
    return (rear + 1) % capacity == front;
}

void Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue is full\n";
        return;
    }
    rear = (rear + 1) % capacity;  
    arr[rear] = x;
    if (front == -1) {
        front = 0;  
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;  
    }
    int temp = arr[front];
    arr[front] = 0;  
    if (front == rear) {  
        front = rear = -1;  
    } else {
        front = (front + 1) % capacity;  
    }
    return temp;
}

int Queue::qsize() {
    if (front == -1) {
        return 0;
    } else if (rear >= front) {
        return rear - front + 1;
    } else {
        return capacity - front + rear + 1;
    }
}

void Queue::qprint() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << arr[rear] << endl;  
    }
}

int Queue::frontel() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;  
    }
    return arr[front];
}

int Queue::rearel() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;  
    }
    return arr[rear];
}

