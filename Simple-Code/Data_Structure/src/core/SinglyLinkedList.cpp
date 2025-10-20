#include "ds/SinglyLinkedList.h"
#include <iostream>

List::List() : head(nullptr) {}

List::~List() {
    NODEPTR current = head;
    while (current) {
        NODEPTR temp = current;
        current = current->next;
        delete temp;
    }
}

int List::emptyList() const {
    return head == nullptr;
}

int List::push(int insertValue) {
    NODEPTR newNode = new Node();
    newNode->info = insertValue;
    newNode->next = head;
    head = newNode;
    return insertValue;
}

int List::pop() {
    if (emptyList()) {
        throw std::runtime_error("Stack is empty");
    }
    int val = head->info;
    NODEPTR temp = head;
    head = head->next;
    delete temp;
    return val;
}

int List::insertAfter(int prevVal, int newVal) {
    NODEPTR current = head;
    while (current) {
        if (current->info == prevVal) {
            NODEPTR newNode = new Node();
            newNode->info = newVal;
            newNode->next = current->next;
            current->next = newNode;
            return newVal;
        }
        current = current->next;
    }
    // If prevVal not found, insert at end
    NODEPTR newNode = new Node();
    newNode->info = newVal;
    newNode->next = nullptr;

    if (emptyList()) {
        head = newNode;
    } else {
        NODEPTR temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return newVal;
}

void List::del(int delVal) {
    if (emptyList()) return;

    // Delete head
    if (head->info == delVal) {
        NODEPTR temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Delete middle/end
    NODEPTR current = head;
    while (current->next) {
        if (current->next->info == delVal) {
            NODEPTR temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

void List::print() const {
    NODEPTR current = head;
    std::cout << "List: ";
    while (current) {
        std::cout << current->info;
        if (current->next) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}
