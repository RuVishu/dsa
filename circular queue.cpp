#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
private:
    Node* rear;

public:
    Queue() : rear(NULL) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == NULL) {
            newNode->next = newNode;
            rear = newNode;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (rear == NULL) {
            cout << "Queue is empty. Nothing to dequeue." << endl;
            return;
        }

        Node* front = rear->next;
        if (front == rear) {
            delete front;
            rear = NULL;
        } else {
            rear->next = front->next;
            delete front;
        }
        cout << "Dequeued one element." << endl;
    }

    void display() {
        if (rear == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = rear->next;
        cout << "Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
