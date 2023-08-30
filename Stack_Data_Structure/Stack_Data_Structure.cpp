#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack stack;
	stack.push(5.3);
	stack.push(3.4);
	stack.push(2.5);
	stack.push(3.9);
	cout << stack;
}
