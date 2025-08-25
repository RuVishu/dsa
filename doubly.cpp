#include "doubly.h"
#include <iostream>
using namespace std;

dnode::dnode()
{
	data=0;
	next=NULL;
	prev=NULL;
}
dnode::dnode(int el)
{
	data=el;
	next=NULL;
	prev=NULL;
}

doubly::doubly()
{
	head=tail=NULL;
}
doubly::~doubly() 
{
    dnode* current = head;
    while (current != NULL) {
        dnode* nextNode = current->next;
        delete current;  
        current = nextNode;  
    }
    head = tail = NULL;  
}

void doubly::insert_dhead(int el)
{
	dnode *newnode=new dnode(el);
	if(head==NULL)
	{
		head=tail=newnode;
		return;
	}
	head->prev=newnode;
	newnode->next=head;
	head=newnode;
}
void doubly::insert_dtail(int el)
{
	dnode *newnode=new dnode(el);
	if(tail==NULL)
	{
		tail=head=newnode;
		return;
	}
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
}
void doubly::del_dhead()
{
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;
		return;
	}
	dnode* temp = head;
    if (head == tail) { 
        head = tail = NULL;
    } 
	else 
	{
        head = head->next;
        head->prev = NULL;
    }

    delete temp;
}
void doubly::del_dtail()
{
	if(tail==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	dnode* temp = tail;
    if (head == tail) { // If there's only one element
        head = tail = NULL;
    } 
	else 
	{
        tail = tail->prev;
        tail->next = NULL;
    }

    delete temp;
}
void doubly::dprint()
{
	dnode *temp = head;
    if (head==NULL && tail==NULL) 
	{
        cout << "List is empty" << endl;
    }

    while (temp != NULL) 
	{
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int doubly::dsize()
{
	if (head == NULL && tail== NULL) 
	{
        return 0;
    }
    int count = 0;
    dnode *temp = head;
    while (temp != NULL) 
	{
        count++;
        temp = temp->next;
    }
    return count;
}

bool doubly::dsearch(int el)
{
	dnode *temp = head;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            return true;  
        }
        temp = temp->next;  
    }
    return false; 
}
void doubly::insert_dmid(int el) {
    dnode* newnode = new dnode(el);

    if (head == NULL) {
        head = newnode;
        return;
    }

    dnode* slow = head;
    dnode* fast = head;

    // Traverse to find the middle node
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the list size is even, slow is at the first of the two middle nodes
    // If the list size is odd, slow is exactly in the middle
    // Insert the new node after the slow pointer (for both odd and even cases)
    
    newnode->next = slow;  // Insert before the slow node
    newnode->prev = slow->prev;

    if (slow->prev != NULL) {
        slow->prev->next = newnode;  // Connect previous node to new node
    } else {
        head = newnode;  // If there was no previous node, update head
    }
    
    slow->prev = newnode; // Connect slow node to new node
}

