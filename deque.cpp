// by including doubly file
#include "DEQUE.H"
#include "DOUBLY.H"
#include <iostream>
using namespace std;

deque::deque(int size)
{
	n=size;
}
deque::~deque()
{
	a.~doubly();
}
bool deque::isEmpty()
{
	return a.head==NULL && a.tail==NULL;
}
bool deque::isFull()
{
	return a.dsize()==n;
}
void deque::insertFront(int x)
{
	a.insert_dhead(x);
}
void deque::insertBack(int x)
{
	a.insert_dtail(x);
}
void deque::delFront()
{
	if (isEmpty()) 
	{
        cout << "Deque is empty. Cannot delete from the front.\n";
        return;
    }
	a.del_dhead();
}
void deque::delBack()
{
	if (isEmpty()) 
	{
        cout << "Deque is empty. Cannot delete from the rear.\n";
        return;
    }
	a.del_dtail();
}
int deque::frontd()
{
	if(isEmpty())
	{
		cout<<"Deque is empty\n";
		return -1;
	}
	return a.head->data;
}
int deque::reard()
{
	if(isEmpty())
	{
		cout<<"Deque is empty\n";
		return -1;
	}
	return a.tail->data;
}
void deque::dqprint()
{
	a.dprint();
}
int deque::dqsize()
{
	return a.dsize();
}
