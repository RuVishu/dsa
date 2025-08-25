#include <iostream>
#include "TSTACK.H"
#include "TQUEUE.H"

using namespace std;

template <typename T>
void stackMenu(int tsize) {
    TStack<T> tstack(tsize);  // Create a generic stack
    int stackChoice;

    while (true) {
        cout << "\nSTACK MENU\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Peek at the top\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full\n";
        cout << "6. Print Stack\n";
        cout << "7. Size of Stack\n";
        cout << "0. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> stackChoice;

        switch (stackChoice) {
            case 1: {
                T el;
                cout << "Enter element: ";
                cin >> el;
                tstack.tpush(el);
                break;
            }
            case 2:
                cout << "Popped element: " << tstack.tpop() << endl;
                break;
            case 3:
                cout << "Top element: " << tstack.tpeek() << endl;
                break;
            case 4:
                cout << (tstack.tisEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 5:
                cout << (tstack.tisFull() ? "Stack is full" : "Stack has space") << endl;
                break;
            case 6:
                tstack.tprint();
                break;
            case 7:
                cout << "Size of stack: " << tstack.tsize() << endl;
                break;
            case 0:
                cout << "Returning to Main Menu...\n";
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}

template <typename T>
void queueMenu(int tsize) {
    TQueue<T> tqueue(tsize);  // Create a generic queue
    int queueChoice;

    while (true) {
        cout << "\nQUEUE MENU\n";
        cout << "1. Enqueue element\n";
        cout << "2. Dequeue element\n";
        cout << "3. Front element\n";
        cout << "4. Rear element\n";
        cout << "5. Check if queue is empty\n";
        cout << "6. Check if queue is full\n";
        cout << "7. Print Queue\n";
        cout << "8. Size of Queue\n";
        cout << "0. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> queueChoice;

        switch (queueChoice) {
            case 1: {
                T el;
                cout << "Enter element: ";
                cin >> el;
                tqueue.tenqueue(el);
                break;
            }
            case 2:
                cout << "Dequeued element: " << tqueue.tdequeue() << endl;
                break;
            case 3:
                cout << "Front element: " << tqueue.tfrontel() << endl;
                break;
            case 4:
                cout << "Rear element: " << tqueue.trearel() << endl;
                break;
            case 5:
                cout << (tqueue.tisEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 6:
                cout << (tqueue.tisFull() ? "Queue is full" : "Queue has space") << endl;
                break;
            case 7:
                tqueue.tprint();
                break;
            case 8:
                cout << "Size of queue: " << tqueue.tsize() << endl;
                break;
            case 0:
                cout << "Returning to Main Menu...\n";
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}

int main() {
    int stackSize, queueSize;
    int dataTypeChoice, menuChoice;

    while (true) {
        cout << "\nMAIN MENU\n";
        cout << "1. Stack Operations\n";
        cout << "2. Queue Operations\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> menuChoice;

        if (menuChoice == 0) {
            cout << "Exiting...\n";
            break;
        }

        cout << "\nSelect Data Type:\n";
        cout << "1. int\n";
        cout << "2. float\n";
        cout << "3. char\n";
        cout << "Enter data type choice: ";
        cin >> dataTypeChoice;

        if (menuChoice == 1) {  // Stack Operations
            cout << "Enter Stack Size: ";
            cin >> stackSize;

            switch (dataTypeChoice) {
                case 1:
                    stackMenu<int>(stackSize);
                    break;
                case 2:
                    stackMenu<float>(stackSize);
                    break;
                case 3:
                    stackMenu<char>(stackSize);
                    break;
                default:
                    cout << "Invalid data type choice! Returning to main menu...\n";
                    break;
            }
        } else if (menuChoice == 2) {  // Queue Operations
            cout << "Enter Queue Size: ";
            cin >> queueSize;

            switch (dataTypeChoice) {
                case 1:
                    queueMenu<int>(queueSize);
                    break;
                case 2:
                    queueMenu<float>(queueSize);
                    break;
                case 3:
                    queueMenu<char>(queueSize);
                    break;
                default:
                    cout << "Invalid data type choice! Returning to main menu...\n";
                    break;
            }
        } else {
            cout << "Invalid menu choice! Please try again.\n";
        }
    }

    return 0;
}



