#include <iostream>
#include "StackNode.h"
#include "Stack.h"

using namespace std;

Stack::Stack() {
    top_node = NULL;
    nodes_amount = 0;
}

Stack::~Stack() {
    this->clear();
}

bool Stack::top_exists() {
    return top_node != NULL;
}

bool Stack::is_empty() {
    return nodes_amount == 0;
}

bool Stack::has_at_least(int min_nodes_amount) {
    return nodes_amount >= min_nodes_amount;
}

void Stack::push(float data) {
    StackNode* new_node = new(StackNode);
    new_node->data = data;
    new_node->next = top_node;
    top_node = new_node;
    nodes_amount++;
}

void Stack::drop() {
    if (!top_exists()) return;
    StackNode* temporal = top_node;
    top_node = top_node->next;
    delete temporal;
    nodes_amount--;
}

float Stack::top() {
    if (!top_exists()) return 0;
    return top_node->data;
}

float Stack::pop() {
    float data = top();
    drop();
    return data;
}

void Stack::swap() {
    if (!top_exists() || !has_at_least(2)) return;
    StackNode* temporal = top_node;
    top_node = top_node->next;
    temporal->next = top_node->next;
    top_node->next = temporal;
}

void Stack::dup() {
    if (!top_exists()) return;
    push(top_node->data);
}

void Stack::depth() {
    push(nodes_amount);
}

void Stack::pick() {
    if (!top_exists()) return;
    int top_node_data = (int)pop();
    if (nodes_amount < top_node_data) return;
    int position_counter = 1;
    for (StackNode* current_node = top_node; current_node != NULL; current_node = current_node->next) {
        if (position_counter == top_node_data) {
            push(current_node->data);
            return;
        }
        position_counter++;
    }
}

void Stack::dupn() {
    if (!top_exists()) return;
    int top_node_data = (int)pop();
    if (top_node_data > nodes_amount) top_node_data = nodes_amount;
    for (int i = 0; i < top_node_data; i++) {
        push(top_node_data);
        pick();
    }
}

void Stack::dropn() {
    if (!top_exists()) return;
    int top_node_data = (int)pop();
    if (top_node_data > nodes_amount) top_node_data = nodes_amount;
    for (int i = 0; i < top_node_data; i++) {
        drop();
    }
}

void Stack::clear() {
    if (!top_exists()) return;
    depth();
    dropn();
}

void Stack::rolld() {
    if (!top_exists()) return;
    int top_node_data = (int)pop();
    if (top_node_data > nodes_amount) top_node_data = nodes_amount;
    if (top_node_data == 1) return;
    int position_counter = 1;
    for (StackNode* current_node = top_node; current_node != NULL; current_node = current_node->next) {
        if (position_counter == top_node_data) {
            StackNode* temporal = top_node;
            top_node = top_node->next;
            temporal->next = current_node->next;
            current_node->next = temporal;
            return;
        }
        position_counter++;
    }
}

void Stack::rollu() {
    if (!top_exists()) return;
    int top_node_data = (int)pop();
    if (top_node_data > nodes_amount || top_node_data == 1) return;
    int position_counter = 1;
    for (StackNode* current_node = top_node; current_node != NULL; current_node = current_node->next) {
        if (position_counter == (top_node_data - 1)) {
            StackNode* temporal = current_node->next;
            current_node->next = current_node->next->next;
            temporal->next = top_node;
            top_node = temporal;
            return;
        }
        position_counter++;
    }
}

void Stack::add() {
    if (!has_at_least(2)) return;
    push(pop() + pop());
}

void Stack::sub() {
    if (!has_at_least(2)) return;
    this->swap();
    push(pop() - pop());
}

void Stack::div() {
    if (!has_at_least(2)) return;
    this->swap();
    push(pop() / pop());
}

void Stack::mult() {
    if (!has_at_least(2)) return;
    push(pop() * pop());
}

void Stack::pot() {
    if (!has_at_least(2)) return;
    push(pow(pop(), pop()));
}

ostream& operator<<(ostream& output, Stack& stack) {
    if (stack.is_empty()) output << "Stack is empty!";
    int position_counter = 1;
    for (StackNode* temporal = stack.top_node; temporal != NULL; temporal = temporal->next) {
        output << temporal->data;
        if (position_counter == 1) output << " <-- top";
        if (temporal->next == NULL) output << " <-- tail";
        output << endl;
        position_counter++;
    }
    output << endl;
    return output;
}
