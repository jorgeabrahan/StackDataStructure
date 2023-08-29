#include "Stack.h"
#include "StackNode.h"

Stack::Stack() {
    top_node = NULL;
    nodes_amount = 0;
}

Stack::~Stack() {
    this->clear();
}

bool Stack::has_at_least(int nodes_amount) {
    return nodes_amount >= 2;
}

void Stack::push(float data) {
    StackNode* new_node = new(StackNode);
    new_node->data = data;
    new_node->next = top_node;
    top_node = new_node;
    nodes_amount++;
}

void Stack::drop() {
    if (top_node == NULL) return;
    StackNode* tmp = top_node;
    top_node = top_node->next;
    delete tmp;
    nodes_amount--;
}

float Stack::top() {
    if (top_node == NULL) return 0;
    return top_node->data;
}

float Stack::pop() {
    float valor = top();
    drop();
    return valor;
}

void Stack::swap() {
    if (top_node == NULL || nodes_amount < 2) return;
    StackNode* tmp = top_node;
    top_node = top_node->next;
    tmp->next = top_node->next;
    top_node->next = tmp;
}

void Stack::dup() {
    if (top_node == NULL) return;
    push(top_node->data);
}

void Stack::depth() {
    push(nodes_amount);
}

void Stack::pick() {
    if (top_node == NULL) return;
    int posicion_nodo_copiar = (int)pop();
    if (nodes_amount < posicion_nodo_copiar) return;
    int posicion_actual = 1;
    for (StackNode* tmp = top_node; tmp != NULL; tmp = tmp->next) {
        if (posicion_actual == posicion_nodo_copiar) {
            push(tmp->data);
            return;
        }
        posicion_actual++;
    }
}

void Stack::dupn() {
    if (top_node == NULL) return;
    int n = (int)pop();
    if (n > nodes_amount) n = nodes_amount;
    for (int i = 0; i < n; i++) {
        push(n);
        pick();
    }
}

void Stack::dropn() {
    if (top_node == NULL) return;
    int n = (int)pop();
    if (n > nodes_amount) n = nodes_amount;
    for (int i = 0; i < n; i++) {
        drop();
    }
}

void Stack::clear() {
    if (top_node == NULL) return;
    depth();
    dropn();
}

void Stack::rolld() {
    if (top_node == NULL) return;
    int n = (int)pop();
    if (n > nodes_amount) n = nodes_amount;
    if (n == 1) return;
    int contador = 1;
    for (StackNode* act = top_node; act != NULL; act = act->next) {
        if (contador == n) {
            StackNode* tmp_tope = top_node;
            top_node = top_node->next;
            tmp_tope->next = act->next;
            act->next = tmp_tope;
            return;
        }
        contador++;
    }
}

void Stack::rollu() {
    if (top_node == NULL) return;
    int n = (int)pop();
    if (n > nodes_amount || n == 1) return;
    int contador = 1;
    for (StackNode* act = top_node; act != NULL; act = act->next) {
        if (contador == (n - 1)) {
            StackNode* tmp_siguiente = act->next;
            act->next = act->next->next;
            tmp_siguiente->next = top_node;
            top_node = tmp_siguiente;
            return;
        }
        contador++;
    }
}

void Stack::add() {
    if (nodes_amount < 2) return;
    push(pop() + pop());
}

void Stack::sub() {
    if (nodes_amount < 2) return;
    this->swap();
    push(pop() - pop());
}

void Stack::div() {
    if (nodes_amount < 2) return;
    this->swap();
    push(pop() / pop());
}

void Stack::mult() {
    if (nodes_amount < 2) return;
    push(pop() * pop());
}

void Stack::pot() {
    if (nodes_amount < 2) return;
    push(pow(pop(), pop()));
}

ostream& operator<<(ostream& output, Stack& stack) {
    if (stack.nodes_amount == 0) output << "Stack is empty!";
    for (StackNode* tmp = stack.top_node; tmp != NULL; tmp = tmp->next) {
        output << tmp->data << ", ";
    }
    return output;
}
