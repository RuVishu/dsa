#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"  // Include Deque header
using namespace std;

int main() {
    int ch, ch2, n, el;

    cout << "Enter Stack, Queue, and Deque Size: ";
    cin >> n;

    Stack stack(n);
    Queue queue(n);  
    deque d(n);  

    while (true) {
        cout << "MENU\n1. Stack\n2. Queue\n3. Deque\n0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:  // Stack Operations
                while (true) {
                    cout << "1. Insert element\n2. Delete element\n";
                    cout << "3. Peek at the top\n4. Check capacity\n";
                    cout << "5. Print Stack\n6. Size\n0. Exit from Stack" << endl;
                    cout << "Enter your choice: ";
                    cin >> ch2;

                    switch (ch2) {
                        case 1:
                            cout << "Enter element: ";
                            cin >> el;
                            stack.push(el);
                            break;

                        case 2:
                            cout << "Popped element: " << stack.pop() << endl;
                            break;

                        case 3:
                            cout << "Top element is: " << stack.peek() << endl;
                            break;

                        case 4:
                            if (stack.isEmpty()) {
                                cout << "Stack is completely empty" << endl;
                            } else {
                                if (stack.isFull()) {
                                    cout << "Stack is full\n";
                                } else {
                                    cout << "Stack has some space available" << endl;
                                }
                            }
                            break;

                        case 5:
                            stack.print();
                            break;

                        case 6:
                            cout << "Size of stack: " << stack.size() << endl;
                            break;

                        case 0:
                            cout << "Returning to main menu..\n";
                            break;

                        default:
                            cout << "Invalid choice! Please try again.\n";
                            break;
                    }

                    if (ch2 == 0) break;
                }
                break;

            case 2:  // Queue Operations
                while (true) {
                    cout << "1. Insert element\n2. Delete element\n";
                    cout << "3. Front element\n4. Rear element\n";
                    cout << "5. Check capacity\n6. Print Queue\n7. Size\n0. Exit from Queue" << endl;
                    cout << "Enter your choice: ";
                    cin >> ch2;

                    switch (ch2) {
                        case 1:
                            cout << "Enter element: ";
                            cin >> el;
                            queue.enqueue(el);
                            break;

                        case 2:
                            cout << "Dequeued element: " << queue.dequeue() << endl;
                            break;

                        case 3:
                            if (!queue.isEmpty()) {
                                cout << "Front element is: " << queue.frontel() << endl;
                            } else {
                                cout << "Queue is empty!" << endl;
                            }
                            break;

                        case 4:
                            if (!queue.isEmpty()) {
                                cout << "Rear element is: " << queue.rearel() << endl;
                            } else {
                                cout << "Queue is empty!" << endl;
                            }
                            break;

                        case 5:
                            if (queue.isEmpty()) {
                                cout << "Queue is completely empty" << endl;
                            } else {
                                if (queue.isFull()) {
                                    cout << "Queue is full\n";
                                } else {
                                    cout << "Queue has some space available" << endl;
                                }
                            }
                            break;

                        case 6:
                            queue.qprint();
                            break;

                        case 7:
                            cout << "Size of queue: " << queue.qsize() << endl;
                            break;

                        case 0:
                            cout << "Returning to main menu..\n";
                            break;

                        default:
                            cout << "Invalid choice! Please try again.\n";
                            break;
                    }

                    if (ch2 == 0) break;
                }
                break;

            case 3:  // Deque Operations
                while (true) {
                    cout << "1. Insert element at front\n2. Insert element at back\n";
                    cout << "3. Delete element from front\n4. Delete element from back\n";
                    cout << "5. Front element\n6. Rear element\n";
                    cout << "7. Check capacity\n8. Print Deque\n9. Size\n0. Exit from Deque" << endl;
                    cout << "Enter your choice: ";
                    cin >> ch2;

                    switch (ch2) {
                        case 1:
                            cout << "Enter element: ";
                            cin >> el;
                            d.insertFront(el);
                            break;

                        case 2:
                            cout << "Enter element: ";
                            cin >> el;
                            d.insertBack(el);
                            break;

                        case 3:
                            if (!d.isEmpty()) {
                                cout << "Deleted element from front: " << d.frontd() << endl; // Ensure delFront returns the deleted value.
                            	d.delFront();
							} else {
                                cout << "Deque is empty. Cannot delete from the front." << endl;
                            }
                            break;

                        case 4:
                            if (!d.isEmpty()) {
                                cout << "Deleted element from back: " << d.reard() << endl; // Ensure delBack returns the deleted value.
                            	d.delBack();
							} else {
                                cout << "Deque is empty. Cannot delete from the back." << endl;
                            }
                            break;

                        case 5:
                            if (!d.isEmpty()) {
                                cout << "Front element is: " << d.frontd() << endl;
                            } else {
                                cout << "Deque is empty!" << endl;
                            }
                            break;

                        case 6:
                            if (!d.isEmpty()) {
                                cout << "Rear element is: " << d.reard() << endl;
                            } else {
                                cout << "Deque is empty!" << endl;
                            }
                            break;

                        case 7:
                            if (d.isEmpty()) {
                                cout << "Deque is completely empty" << endl;
                            } else {
                                if (d.isFull()) {
                                    cout << "Deque is full\n";
                                } else {
                                    cout << "Deque has some space available" << endl;
                                }
                            }
                            break;

                        case 8:
                            d.dqprint();
                            break;

                        case 9:
                            cout << "Size of deque: " << d.dqsize() << endl;
                            break;

                        case 0:
                            cout << "Returning to main menu..\n";
                            break;

                        default:
                            cout << "Invalid choice! Please try again.\n";
                            break;
                    }

                    if (ch2 == 0) break;
                }
                break;

            case 0:
                cout << "Exiting program..\n";
                return 0;

            default:
                cout << "Invalid choice...\n";
                break;
        }
    }

    return 0;
}

