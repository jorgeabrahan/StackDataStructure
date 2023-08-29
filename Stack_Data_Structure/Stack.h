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

    // --------- Metodos basicos --------- //
    void push(float);
    void drop();
    float top();
    float pop();

    // --------- Metodos de manejo --------- //
    void swap();
    void dup();
    void depth();
    void pick();
    void dupn();
    void dropn();
    void rolld();
    void rollu();
    void clear();

    // --------- Metodos de operacion --------- //
    // todos contemplan al ultimo nodo como el segundo en la operacion porque la pila funciona en post-orden
    // para todos los metodos, los dos ultimos nodos se eliminan y se coloca el resultado del valor
    void add();
    void sub();
    void div();
    void mult();
    void pot();
};

