// singly.cpp
#include "singly.h"
#include <iostream>
using namespace std;

node::node() 
{
    data = 0;
    next = NULL;
}

node::node(int el) 
{
    data = el;
    next = NULL;
}

singly::singly() 
{
    head = NULL;
}

void singly::insert_head(int el) 
{
    node *newnode = new node();
    if (head == NULL) 
	{
        head = newnode;
        head->data=el;
        return;
    }
    newnode->data = el;
    newnode->next = head;
    head = newnode;
}

void singly::print() 
{
    node *temp = head;
    if (head == NULL) 
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

void singly::del_head() 
{
    if (head == NULL) 
	{
        cout << "Empty linked list" << endl;
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}

int singly::size() 
{
    if (head == NULL) 
	{
        return 0;
    }
    int count = 0;
    node *temp = head;
    while (temp != NULL) 
	{
        count++;
        temp = temp->next;
    }
    return count;
}

void singly::insert_last(int el)
{
	node *newnode=new node(el);
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;	
}

void singly::del_last() 
{
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    // If there's only one element in the list
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    // Traverse to the second-last node
    node *temp = head;
    while (temp->next->next != NULL) 
	{
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}


bool singly::search(int el)
{
    node *temp = head;
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

void singly::insert_mid(int el)
{
    node* newNode = new node(el);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *slow = head;
    node *fast = head;
    node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == NULL) //even size [el will added in mid]
    {
        newNode->next = slow;
        prev->next = newNode;
    }
    else //odd size [el is added after mid]
    {
        newNode->next = slow->next;
        slow->next = newNode;
    }
}




