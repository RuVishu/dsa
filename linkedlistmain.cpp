#include <iostream>
#include "singly.h"    
#include "doubly.h"    
#include "circular.h"  
#include "cd.h"        

using namespace std;

int main() {
    singly list;      
    doubly list2;      
    circular list3;    
    cd list4;          

    int mainChoice;    
    int subChoice;     
    int element;       

    // Main program loop
    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Circular Singly Linked List\n";
        cout << "4. Circular Doubly Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:  // Singly Linked List Menu
                while (true) {
                    cout << "\n--- Singly Linked List Menu ---\n";
                    cout << "1. Insert at head\n";
                    cout << "2. Insert at tail\n";
                    cout << "3. Insert at middle\n";
                    cout << "4. Delete head\n";
                    cout << "5. Delete tail\n";
                    cout << "6. Search for an element\n";
                    cout << "7. Size of linked list\n";
                    cout << "8. Print singly linked list\n";
                    cout << "0. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter element to insert at head: ";
                            cin >> element;
                            list.insert_head(element);
                            break;
                        case 2:
                            cout << "Enter element to insert at tail: ";
                            cin >> element;
                            list.insert_last(element);
                            break;
                        case 3:
                            cout << "Enter element to insert at middle: ";
                            cin >> element;
                            list.insert_mid(element);
                            break;
                        case 4:
                            list.del_head();
                            break;
                        case 5:
                            list.del_last();
                            break;
                        case 6:
                            cout << "Enter element to search: ";
                            cin >> element;
                            if (list.search(element)) {
                                cout << "Element found in the list.\n";
                            } else {
                                cout << "Element not found in the list.\n";
                            }
                            break;
                        case 7:
                            cout << "Size of singly linked list: " << list.size() << endl;
                            break;
                        case 8:
                            cout << "Singly linked list: ";
                            list.print();
                            break;
                        case 0:
                            break;  
                        default:
                            cout << "Invalid choice! Please try again.\n";
                            break;
                    }
                    if (subChoice == 0) break; 
                }
                break;

            case 2:  // Doubly Linked List Menu
                while (true) {
                    cout << "\n--- Doubly Linked List Menu ---\n";
                    cout << "1. Insert at head\n";
                    cout << "2. Insert at tail\n";
                    cout << "3. Insert at middle\n";
                    cout << "4. Search for an element\n";
                    cout << "5. Delete head\n";
                    cout << "6. Delete tail\n";
                    cout << "7. Size of linked list\n";
                    cout << "8. Print doubly linked list\n";
                    cout << "0. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter element to insert at head: ";
                            cin >> element;
                            list2.insert_dhead(element);
                            break;
                        case 2:
                            cout << "Enter element to insert at tail: ";
                            cin >> element;
                            list2.insert_dtail(element);
                            break;
                        case 3:
                            cout << "Enter element to insert at middle: ";
                            cin >> element;
                            list2.insert_dmid(element);
                            break;
                        case 4:
                            cout << "Enter element to search: ";
                            cin >> element;
                            if (list2.dsearch(element)) {
                                cout << "Element found in the list.\n";
                            } else {
                                cout << "Element not found in the list.\n";
                            }
                            break;
                        case 5:
                            list2.del_dhead();
                            break;
                        case 6:
                            list2.del_dtail();
                            break;
                        case 7:
                            cout << "Size of doubly linked list: " << list2.dsize() << endl;
                            break;
                        case 8:
                            cout << "Doubly linked list: ";
                            list2.dprint();
                            break;
                        case 0:
                            break;  
                        default:
                            cout << "Invalid choice! Please try again.\n";
                            break;
                    }
                    if (subChoice == 0) break; 
                }
                break;

            case 3:  // Circular Singly Linked List Menu
                while (true) {
                    cout << "\n--- Circular Singly Linked List Menu ---\n";
                    cout << "1. Insert at Front\n";
                    cout << "2. Insert at Back\n";
                    cout << "3. Delete from Front\n";
                    cout << "4. Delete from Back\n";
                    cout << "5. Display Front\n";
                    cout << "6. Display Back\n";
                    cout << "7. Print circular linked list\n";
                    cout << "8. Size of circular linked list\n";
                    cout << "0. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter element to insert at front: ";
                            cin >> element;
                            list3.insert_front(element);
                            break;
                        case 2:
                            cout << "Enter element to insert at back: ";
                            cin >> element;
                            list3.insert_back(element);
                            break;
                        case 3:
                            list3.del_front();
                            break;
                        case 4:
                            list3.del_back();
                            break;
                        case 5:
                            if (list3.csize() > 0) {
                                cout << "Front element: " << list3.front() << endl;
                            } else {
                                cout << "List is empty.\n";
                            }
                            break;
                        case 6:
                            if (list3.csize() > 0) {
                                cout << "Back element: " << list3.back() << endl;
                            } else {
                                cout << "List is empty.\n";
                            }
                            break;
                        case 7:
                            cout << "Circular linked list: ";
                            list3.cprint();
                            break;
                        case 8:
                            cout << "Size of circular linked list: " << list3.csize() << endl;
                            break;
                        case 0:
                            break;  
                        default:
                            cout << "Invalid choice! Please try again.\n";
                            break;
                    }
                    if (subChoice == 0) break; 
                }
                break;

            case 4:  // Circular Doubly Linked List Menu
                while (true) {
                    cout << "\n--- Circular Doubly Linked List Menu ---\n";
                    cout << "1. Insert at Front\n";
                    cout << "2. Insert at Back\n";
                    cout << "3. Delete from Front\n";
                    cout << "4. Delete from Back\n";
                    cout << "5. Search for an element\n";
                    cout << "6. Print circular doubly linked list\n";
                    cout << "7. Size of circular doubly linked list\n";
                    cout << "0. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter element to insert at front: ";
                            cin >> element;
                            list4.hinsert(element);
                            break;
                        case 2:
                            cout << "Enter element to insert at back: ";
                            cin >> element;
                            list4.tinsert(element);
                            break;
                        case 3:
                            list4.delh();
                            break;
                        case 4:
                            list4.delt();
                            break;
                        case 5:
                            cout << "Enter element to search: ";
                            cin >> element;
                            if (list4.cdSearch(element)) {
                                cout << "Element found in the list.\n";
                            } else {
                                cout << "Element not found in the list.\n";
                            }
                            break;
                        case 6:
                            cout << "Circular doubly linked list: ";
                            list4.cdPrint();
                            break;
                        case 7:
                            cout << "Size of circular doubly linked list: " << list4.cdsize() << endl;
                            break;
                        case 0:
                            break;  // Return to main menu
                        default:
                            cout << "Invalid choice! Please try again.\n";
                            break;
                    }
                    if (subChoice == 0) break; 
                }
                break;

            case 0:  // Exit
                cout << "Exiting program.\n";
                return 0;  

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0; 
}

