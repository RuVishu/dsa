#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int x) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    arr[++top] = x;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return arr[top--];
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return arr[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == capacity - 1;
}

void Stack::print() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack:\n";
    for (int i = top; i >=0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int Stack::size()
{
	return top + 1;
}
bool Stack::search(int el)
{
	for(int i=top;i>=0;i--)
	{
		if(arr[i]==el)
		{
			return true;
		}
	}
	return false;
}
