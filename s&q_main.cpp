#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	stack a;
	a.isEmpty();
	a.push(7);
	a.push(4);
	a.push(6);
	a.pop();
	a.isEmpty();
	a.peek();
	a.print();
}
