#include "ds/Stack.h"
#include <iostream>
#include <stdexcept>

Stack::Stack() : top(nullptr), size(0) {}

Stack::~Stack() {
    while (!isEmpty()) {
        NODEPTR temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::push(int val) {
    NODEPTR newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    size++;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    int data = top->data;
    NODEPTR temp = top;
    top = top->next;
    delete temp;
    size--;
    return data;
}

int Stack::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return top->data;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

int Stack::getSize() const {
    return size;
}
