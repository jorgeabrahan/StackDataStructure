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
    void push(float);   // add top node
    void drop();        // remove top node
    float top();        // return top node
    float pop();        // remove and return top node

    // --------- Management methods --------- //
    void swap();        // swap top nodes
    void dup();         // duplicate top nodes
    void depth();       // add nodes amount as top node
    void pick();        // copies specified node and paste it at the top
    void dupn();        // duplicates n nodes at the top of the stack
    void dropn();       // removes n nodes from the top of the stack
    void rolld();       // rolls a node down
    void rollu();       // rolls a node up
    void clear();       // clears the stack

    // --------- Operation methods --------- //
    // Since stacks work in post order, the next method the top node will be the second number in the operations
    // therefore for the stack: 3(top) - 4 - 2 if the subtract method is called then this will happen: 4 - 3 resulting in: 1
    void add();
    void sub();
    void div();
    void mult();
    void pot();
};

