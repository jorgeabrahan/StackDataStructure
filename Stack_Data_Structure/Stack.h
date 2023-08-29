#pragma once

#include <iostream>
class StackNode;

using namespace std;

class Stack
{
private:
    StackNode* top_node;
    int nodes_amount;
public:
    friend ostream& operator<<(ostream&, Stack&);

    Stack();
    ~Stack();

    bool top_exists();
    bool is_empty();
    bool has_at_least(int);

    // --------- Basic methods --------- //
    void push(float);
    void drop();
    float top();
    float pop();

    // --------- Management methods --------- //
    void swap();
    void dup();
    void depth();
    void pick();
    void dupn();
    void dropn();
    void rolld();
    void rollu();
    void clear();

    // --------- Operation methods --------- //
    // Since stacks work in post order, the next method the top node will be the second number in the operations
    // therefore for the stack: 3(top) - 4 - 2 if the subtract method is called then this will happen: 4 - 3 resulting in: 1
    void add();
    void sub();
    void div();
    void mult();
    void pot();
};

