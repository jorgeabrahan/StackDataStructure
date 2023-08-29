class Stack;

#pragma once
class StackNode {
private:
    float data;
    StackNode* next;

    friend Stack;
    friend ostream& operator<<(ostream&, Stack&);
};
