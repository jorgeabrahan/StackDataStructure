#pragma once
#include <iostream>
class Stack;

using namespace std;

class StackNode {
private:
    float data;
    StackNode* next;

    friend Stack;
    friend ostream& operator<<(ostream&, Stack&);
};
