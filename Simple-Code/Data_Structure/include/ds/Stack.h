#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
 public:
  typedef struct Node {
    int data;
    struct Node* next;
  } Node;
  typedef Node* NODEPTR;
  NODEPTR top;
 private:
  int size;
 public:
  Stack();
  ~Stack();
  void push(int val);
  int pop();
  int peek();
  int getSize() const;
  bool isEmpty() const;
};

#endif // STACK_H
