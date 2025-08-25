#include "circular.h"
#include <iostream>
using namespace std;

cnode::cnode() 
{
    data = 0;
    next = NULL;
}

cnode::cnode(int el) 
{
    data = el;
    next = NULL;
}

circular::circular()
{
    cursor = NULL;
}

int circular::back()
{
    return cursor->data;
}

int circular::front()
{
    return cursor->next->data;
}

void circular::insert_back(int el)
{
    cnode *newnode = new cnode(el);
    if (cursor == NULL)
    {
        cursor = newnode;
        cursor->next = cursor;  
        return;
    }
    newnode->next = cursor->next;
    cursor->next = newnode;
    cursor = newnode;
    
}

void circular::insert_front(int el)
{
    cnode *newnode = new cnode(el);
    if (cursor == NULL)
    {
        cursor = newnode;
        cursor->next = cursor;  // Complete the circle for the first node
        return;
    }
    newnode->next = cursor->next;
    cursor->next = newnode;
}

void circular::cprint()
{
    if (cursor == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    
    cnode *temp = cursor->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != cursor->next);
    cout << endl;
}

int circular::csize()
{
    if (cursor == NULL)
    {
        return 0;
    }
    
    int count = 1;  // There's at least one node
    cnode *temp = cursor->next;
    while (temp != cursor)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void circular::del_back()
{
    if (cursor == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    cnode *temp = cursor->next;
    if (temp == cursor)  // Only one node in the list
    {
        delete cursor;
        cursor = NULL;
        return;
    }

    while (temp->next != cursor)
    {
        temp = temp->next;
    }
    temp->next = cursor->next;
    delete cursor;
    cursor = temp;
}

void circular::del_front()
{
    if (cursor == NULL)
    {
        cout << "empty list" << endl;
        return;
    }

    cnode *temp = cursor->next;
    if (temp == cursor)  
    {
        delete cursor;
        cursor = NULL;
        return;
    }

    cursor->next = temp->next;
    delete temp;
}

bool circular::csearch(int el) {
    if (cursor == NULL) {
        return false;  // List is empty
    }

    cnode* temp = cursor->next;  // Start from the node after cursor

    do {
        if (temp->data == el) {
            return true;  // Element found
        }
        temp = temp->next;  // Move to the next node
    } while (temp != cursor->next);  // Continue until we loop back

    return false;  // Element not found
}

